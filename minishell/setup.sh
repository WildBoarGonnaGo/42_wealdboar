#!/bin/bash

clang -Wall -Wextra -Werror -g main.c sh_envp_search.c sh_line_ansys.c alloc_free_2.c sh_parcer.c \
execve_args.c sh_gnl.c sh_user_bin.c addchar.c memrealloc.c ./func_dir/*.c -o minishell -L./libc -lft 
