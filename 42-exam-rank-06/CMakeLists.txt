cmake_minimum_required(VERSION 3.1.0)

project(mini_serv)
add_compile_options(-Wall -Wextra -Werror -g)
add_executable(${PROJECT_NAME} "mini_serv.c")
