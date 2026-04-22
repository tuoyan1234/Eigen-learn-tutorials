cmake_minimum_required(VERSION 3.10)

project(SPACE-TRANS)

find_package(Eigen3 REQUIRED)

add_executable(SPACE-TRANS sapce_transfor.cpp)
target_link_libraries(SPACE-TRANS Eigen3::Eigen)