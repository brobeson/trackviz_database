add_library(
  trackvis_database
  trackvis_database/database.cpp
  trackvis_database/database.hpp
)
target_include_directories(trackvis_database PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(trackvis_database PUBLIC cxx_std_17)