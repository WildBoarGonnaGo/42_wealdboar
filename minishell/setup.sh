#!/bin/bash

clang -Wall -Wextra -Werror -g main.c sh_envp_search.c sh_line_ansys.c alloc_free_2.c \
execve_args.c sh_gnl.c sh_user_bin.c addchar.c memrealloc.c sh_parcer.c sh_spec_cases.c \
sh_redirects.c sh_env_linefix.c sh_free_str.c sh_parcer_envp_fix.c sh_pipe_block_fix.c \
sh_ignore_colon.c sh_line_err_parse.c sh_err_analisys.c sh_err_noarg_com.c sh_fork_mem_free.c \
./func_dir/*.c -o minishell -L./libc -lft 
