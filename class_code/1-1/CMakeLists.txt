cmake_minimum_required(VERSION 3.18)
project(sys_cost)
set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS}  -g ")
aux_source_directory(. SRC_cost)
add_executable(main ${SRC_cost})