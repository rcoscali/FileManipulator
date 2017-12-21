# Minimum cmake version
cmake_minimum_required(VERSION 3.5)

# Name our project
project(FileManipulator)

# Define test command
set(CMAKE_CPPTEST_COMMAND cpptests)

# Create lib target 
add_library(file_manipulator src/FileManipulator.cpp)
target_compile_options(file_manipulator PUBLIC "-std=c++11")
include_directories(AFTER include)
target_include_directories(file_manipulator SYSTEM BEFORE PRIVATE googletest/googletest/include)

# Create static library target gtestall
add_library(gtestall STATIC googletest/googletest/src/gtest-all.cc)
target_compile_options(gtestall PUBLIC "-std=c++11")
target_include_directories(gtestall PRIVATE googletest/googletest)
target_include_directories(gtestall SYSTEM BEFORE PRIVATE googletest/googletest/include)

# Create unitary test exe
add_executable(cpptests tests/main.cpp tests/FileManipulator_constructor_tests.cpp)
target_compile_options(cpptests PUBLIC "-std=c++11")
target_include_directories(cpptests PRIVATE googletest/googletest)
target_include_directories(cpptests PRIVATE src)
target_include_directories(cpptests SYSTEM BEFORE PRIVATE googletest/googletest/include)
target_link_libraries(cpptests "file_manipulator;gtestall;pthread")
add_test(NAME cpptests COMMAND cpptests)

# Add make check target
add_custom_target(check COMMAND ${CMAKE_CPPTEST_COMMAND})
