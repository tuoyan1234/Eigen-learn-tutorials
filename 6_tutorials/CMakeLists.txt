cmake_minimum_required(VERSION 3.10)

project(MATRIX_INIT)

find_package(Eigen3 REQUIRED)

add_executable(MATRIX_INIT special_init.cpp)
target_link_libraries(MATRIX_INIT Eigen3::Eigen)