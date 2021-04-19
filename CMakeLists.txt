cmake_minimum_required(VERSION 3.13)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp problem.h problem.cpp node.h node.cpp)