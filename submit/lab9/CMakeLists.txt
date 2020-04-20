cmake_minimum_required(VERSION 3.16)
project(lab9)

set(CMAKE_CXX_STANDARD 14)

#include_directories(exercises/2-sorts)
#include_directories(exercises/3-stats)
include_directories(exercises/4-time)

add_executable(lab9
        #exercises/2-sorts/main.cc
        #exercises/2-sorts/sorts.cc
        #exercises/2-sorts/sorts.hh
        #exercises/3-stats/main.cc
        #exercises/3-stats/ops.cc
        #exercises/3-stats/ops.hh
        #exercises/3-stats/sorts.cc
        #exercises/3-stats/sorts.hh
        exercises/4-time/main.cc
        exercises/4-time/sorts.cc
        exercises/4-time/sorts.hh
        exercises/4-time/now.cc
        exercises/4-time/now.hh)
