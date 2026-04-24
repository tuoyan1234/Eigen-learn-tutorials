cmake_minimum_required(VERSION 3.10)

project(CLASS_MATRIX)

find_package(Eigen3 REQUIRED)

add_executable(CLASS_MATRIX Matrix_vector_algorithm.cpp)
target_link_libraries(CLASS_MATRIX Eigen3::Eigen)