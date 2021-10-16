cmake_minimum_required(VERSION 3.17)

project(St_student)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-I ./")
aux_source_directory(./ main)
add_executable(St_main ${main})