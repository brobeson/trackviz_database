# TrackVis Database Schema

TrackVis databases are JSON files.
There are two types of databases: meta-data and update meta-data.
The meta-data file contains the tracking meta-data.
The update meta-data file contains meta-data about the tracker's online updates.

1. table of contents
{:toc}

## A Note About Bounding Boxes

For brevity, this document uses *bounding box* as a data type.
A bounding box is a 4x1 array of floating point or integer values.
The array values are `[upper left x, upper left y, width, height]`.

## Meta-Data JSON File

This section describes the contents of the meta-data file.
The file consists of one JSON object.
The table below describes the fields of that object.
All the fields are required.
If data is not available for a field, its value must be `null`.

| Key | Type | Description |
|:---|:---|:---|
| `dataset` | string | The name of the dataset that contains the `sequence`. |
| `frames` | array | The list of meta-data associated with each frame in the sequence. See [Frame Meta-Data](#frame_meta_data) for details. |
| `ious` | array | The bounding box overlap between the `target_box`es and the sequence's ground truth bounding boxes. This is an Nx1 array; N is the number of frames in the sequence. **Every frame must have an entry in this array.** The array elements are floating point values in the range [0, 1]. |
| `numpy_versin` | string | The version of numpy used by the tracker. |
| `sequence_name` | string | The name of the sequence for this meta-data file. |
| `torch_version` | string | The version of PyTorch used by the tracker. |

### Frame Meta-Data

The `frames` array list of frame objects.
This table describes the data in each frame object.

| Key | Type | Description |
|:---|:---|:---|
| `target_box` | bounding box | The bounding box around the target found by the tracker in this frame. |
| `regressed_target_box` | bounding box | The target bounding box after applying a regression model to the `target_box`. |
| `candidates` | array | The bounding boxes for the candidate samples. Each element of th array is a bounding box. |
| `candidate_scores` | array | The scores from the neural network for each candidate sample. This is an Nx2 array. N is the number of candidate samples for this frame. The 0th column are the background scores for each sample, and the 1st column are the target scores for each samples. |
| `positive_training_samples` | array | The target training samples gathered from this frame. This is an array of bounding boxes. |
| `negative_training_samples` | array | The background training samples gether from this frame. This is an array of bounding boxes. |
| `dequeued_positive_features` | boolean | `true` indicates that the tracker dequeued previous positive training features from its online update training dataset. `false` or `null` indicates the tracker did not dequeue any features. |
| `dequeued_negative_features` | boolean | `true` indicates that the tracker dequeued previous negative training features from its online update training dataset. `false` or `null` indicates the tracker did not dequeue any features. |
