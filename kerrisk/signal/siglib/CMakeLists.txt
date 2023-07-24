cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
project(siglib)

add_library(${PROJECT_NAME} SHARED sigset.h sigset.cpp)
