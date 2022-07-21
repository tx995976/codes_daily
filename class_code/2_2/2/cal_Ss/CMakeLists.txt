cmake_minimum_required(VERSION 3.17)

project(Ss_cal)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-I ./")
set(CMAKE_BUILD_TYPE "DEBUG")
aux_source_directory(./ main)
add_executable(main ${main})