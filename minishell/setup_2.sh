#!/bin/bash

clang -Wall -Wextra -Werror -g ./srcs/*.c ./srcs/func_dir/*.c -o minishell -L./libc -lft 
