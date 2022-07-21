cmake_minimum_required(VERSION 3.18)
project(test)
set(CMAKE_BUILD_TYPE "DEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS}  -g -Wall")
aux_source_directory(./src SRC_test)
add_executable(main ${SRC_test})




