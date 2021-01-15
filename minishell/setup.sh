#!/bin/bash

clang -Wall -Wextra -Werror -g main.c sh_envp_search.c sh_line_ansys.c alloc_free_2.c \
execve_args.c get_next_line.c sh_user_bin.c addchar.c ./lcreola_080120/env.c \
./lcreola_080120/echo.c ./lcreola_080120/pwd.c -o minishell -L./libc -lft
