cmake_minimum_required(VERSION 3.15)
project(rick_recip_clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(rick_recip_clion
        src/lista.h
        src/main.cpp
        src/recip.cpp
        src/recip.h)
