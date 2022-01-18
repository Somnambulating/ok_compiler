project(MyCaculator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

# googletest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(MyTests test.cpp)
target_link_libraries(MyTests ${GTEST_INCLUDE_DIRS})
gtest_discover_tests(hello_test)
enable_testing()

# main
# add_executable(MyCaculator main.cpp)
# target_link_libraries(MyCaculator tools)