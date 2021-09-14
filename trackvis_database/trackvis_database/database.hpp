#ifndef TRACKVIS_DATABASE_DATABASE_HPP
#define TRACKVIS_DATABASE_DATABASE_HPP

#include <string_view>

namespace trackvis
{
  class sequence
  {
  public:
    [[nodiscard]] std::string_view dataset() const;
    [[nodiscard]] std::string_view name() const;
    [[nodiscard]] std::string_view numpy_version() const;
    [[nodiscard]] std::string_view torch_version() const;

  private:
  };
}  // namespace trackvis

#endif
