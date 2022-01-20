cmake_minimum_required(VERSION 3.14)

project(MyCaculator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

# llvm
# include_directories(/home/descosmos/tools/llvm-project/llvm/include/llvm)

# googletest
find_package(GTest REQUIRED)
enable_testing()
include(GoogleTest)
add_executable(MyTest test.cpp)
target_link_libraries(MyTest tools gtest gtest_main gmock pthread)
gtest_discover_tests(MyTest)        # gtest_discover_tests make the vscode to execute [MyTest] through test button.

# example
add_subdirectory(example)

# main
add_executable(MyCaculator main.cpp)
target_link_libraries(MyCaculator tools)
