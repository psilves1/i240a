cmake_minimum_required(VERSION 3.16)
project(prj2_sol)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(prj2_sol
        arrayseq.hh
        command.cc
        command.hh
        dlinkseq.hh
        nums.cc
        seq-test.cc
        seq.hh)
