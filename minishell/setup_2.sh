#!/bin/bash

clang -Wall -Wextra -Werror -g ./srcs/*.c ./func_dir/*.c -o minishell -L./libc -lft 
