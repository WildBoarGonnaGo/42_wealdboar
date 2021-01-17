#!/bin/bash

clang -Wall -Wextra -Werror -g main.c sh_envp_search.c sh_line_ansys.c alloc_free_2.c \
execve_args.c get_next_line.c sh_user_bin.c addchar.c ./func_dir/env.c \
./func_dir/echo.c ./func_dir/pwd.c -o minishell -L./libc -lft
