cmake_minimum_required(VERSION 3.10)

project(CLASS_BLOCK)

find_package(Eigen3 REQUIRED)

add_executable(CLASS_BLOCK class_block.cpp)
target_link_libraries(CLASS_BLOCK Eigen3::Eigen)