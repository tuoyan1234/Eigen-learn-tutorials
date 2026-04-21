cmake_minimum_required(VERSION 3.10)

project(CLASS_ARRAY)

find_package(Eigen3 REQUIRED)

add_executable(CLASS_ARRAY class_array.cpp)
target_link_libraries(CLASS_ARRAY Eigen3::Eigen)