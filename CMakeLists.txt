cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project src/main.cpp src/sculptor.cpp src/figuraGeometrica.cpp src/figuraGeometrica.hpp src/sculptor.cpp src/sculptor.hpp src/voxel.hpp)