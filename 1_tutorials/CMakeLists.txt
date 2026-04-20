cmake_minimum_required(VERSION 3.10)

project(tutorial_1)

find_package(Eigen3 REQUIRED)

add_executable(tutorial_1 main.cpp)
target_link_libraries(tutorial_1 Eigen3::Eigen)