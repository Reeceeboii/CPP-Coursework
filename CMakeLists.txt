cmake_minimum_required(VERSION 3.14)
project(CPP-Coursework)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP-Coursework
        src/vote.cpp
        src/vote.h
        src/election.cpp
        src/election.h src/main.cpp)