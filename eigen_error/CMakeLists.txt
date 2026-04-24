cmake_minimum_required(VERSION 3.10)

project(MATRIX_INIT)

find_package(Eigen3 REQUIRED)

add_executable(EIGEN_ERR eigen_error.cpp)
target_link_libraries(EIGEN_ERR Eigen3::Eigen)