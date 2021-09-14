cmake_minimum_required(VERSION 3.12)

include(FetchContent)
FetchContent_Declare(
  cmake-tools
  GIT_REPOSITORY https://github.com/brobeson/cmake-tools.git
  GIT_TAG main
)
FetchContent_MakeAvailable(cmake-tools)
list(APPEND CMAKE_MODULE_PATH "${cmake-tools_SOURCE_DIR}")

include(CMakeToolsVersionFromGit)
project(
  trackvis-database
  DESCRIPTION "A library for reading and writing tracking meta-data."
  HOMEPAGE_URL "https://brobeson.github.com/trackvis_database"
  LANGUAGES CXX
)

include(CMakeToolsDefaultCompileOptions)
add_subdirectory(trackvis_database)

# string(
#   CONCAT
#     MEMORYCHECK_COMMAND_OPTIONS
#     "--quiet"
#     " --gen-suppressions=all"
#     " --tool=memcheck"
#     " --leak-check=yes"
#     " --track-origins=yes"
#     " --error-exitcode=1"
# )
# include(CTest)
# if(BUILD_TESTING)
#   add_subdirectory(unit_tests)
# endif()
