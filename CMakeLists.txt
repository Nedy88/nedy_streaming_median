cmake_minimum_required(VERSION 3.10)

project(StreamMedian)

add_library(StreamMedianLib stream_median.cpp stream_median.hpp)

add_executable(Example example.cpp)

target_link_libraries(Example PRIVATE StreamMedianLib)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(StreamMedianTest stream_median_test.cpp)
target_link_libraries(StreamMedianTest gtest_main StreamMedianLib)

include(GoogleTest)
gtest_discover_tests(StreamMedianTest)