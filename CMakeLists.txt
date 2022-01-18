cmake_minimum_required(VERSION 3.14)

project(MyCaculator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

# googletest
find_package(GTest REQUIRED)
enable_testing()
include(GoogleTest)
add_executable(MyTest test.cpp)
target_link_libraries(MyTest tools gtest gtest_main gmock pthread)

# gtest_discover_tests make the vscode to execute [MyTest] through test button.
gtest_discover_tests(MyTest)

# main
add_executable(MyCaculator main.cpp)
target_link_libraries(MyCaculator tools)
