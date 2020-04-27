cmake_minimum_required(VERSION 3.16)
project(lab10)

set(CMAKE_CXX_STANDARD 14)

include_directories(exercises/1-fact)
include_directories(exercises/2-tdd)

add_executable(lab10
        exercises/1-fact/fact.cc
        exercises/1-fact/fact.hh
        exercises/1-fact/main.cc
        exercises/1-fact/test-main.cc
        exercises/2-tdd/digit-sum.cc
        exercises/2-tdd/digit-sum.hh
        exercises/2-tdd/main.cc
        exercises/2-tdd/test-main.cc
        exercises/Makefile exercises/2-tdd/catch.h)
