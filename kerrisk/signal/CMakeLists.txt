cmake_minimum_required(VERSION 3.16)

project(sigset)

add_library(${PROJECT_NAME} SHARED sigset.h sigset.cpp)
