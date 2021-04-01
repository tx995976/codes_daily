cmake_minimum_required(version 2.8.12)
project(lib_link)

add_library(user
    STATIC
        member.hpp
        member.cpp
        data.cpp
)