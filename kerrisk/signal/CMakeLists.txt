cmake_minimum_required(VERSION 3.16)

project(sigtrain)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-v)

add_executable(${PROJECT_NAME} procmask.cpp sigset/sigset.h)
add_subdirectory(sigset)
target_include_directories(${PROJECT_NAME} PUBLIC sigset)
target_link_directories(${PROJECT_NAME} PUBLIC xcode/sigset/Debug)
target_link_libraries(${PROJECT_NAME} PUBLIC -lsigset)
