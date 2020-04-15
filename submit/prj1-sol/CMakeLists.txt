cmake_minimum_required(VERSION 3.16)
project(prj1_sol)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wordcounts
        main.cc
        main.h)
