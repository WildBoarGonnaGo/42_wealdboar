# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 04:55:09 by wealdboar         #+#    #+#              #
#    Updated: 2021/03/16 19:59:43 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ./libc/libsh.a

EXEC_FILE = minishell

SRC =	./srcs/addchar.c      				\
	 	./srcs/alloc_free_2.c				\
		./srcs/execve_args.c				\
		./srcs/memrealloc.c			        \
		./srcs/sh_bin_pipes_over.c			\
		./srcs/sh_bin_search_body.c			\
		./srcs/sh_create_new_lst.c		    \
		./srcs/sh_delims_override.c     	\
		./srcs/sh_env_linefix.c  			\
		./srcs/sh_envp_dupl.c				\
		./srcs/sh_envp_search.c 			\
		./srcs/sh_err_analisys.c			\
		./srcs/sh_err_noarg_com.c			\
		./srcs/sh_find_elem.c				\
		./srcs/sh_find_elem_utils.c			\
		./srcs/sh_find_elem_utils_2.c		\
		./srcs/sh_fork_mem_free.c			\
		./srcs/sh_free_str.c    			\
		./srcs/sh_gnl.c         			\
		./srcs/sh_ignore_colon.c			\
		./srcs/sh_line_ansys.c				\
		./srcs/sh_line_err_parse.c			\
		./srcs/sh_list_semicol_fix.c		\
		./srcs/sh_lst_to_arr2.c				\
		./srcs/sh_noarg_token_status.c		\
		./srcs/sh_parcer.c	    			\
		./srcs/sh_parcer_envp_fix.c			\
		./srcs/sh_pipe_block_fix.c  		\
		./srcs/sh_redirects.c			   	\
		./srcs/sh_set_arr2_strbound.c		\
		./srcs/sh_signal_proc.c	   			\
		./srcs/sh_spec_cases.c	    		\
		./srcs/sh_spec_char_handle.c		\
		./srcs/sh_user_bin.c        		\
		./srcs/func_dir/cd.c                \
		./srcs/func_dir/echo.c              \
		./srcs/func_dir/env.c               \
		./srcs/func_dir/exit.c              \
		./srcs/func_dir/export.c            \
		./srcs/func_dir/export_cat.c        \
		./srcs/func_dir/export_utils.c      \
		./srcs/func_dir/pwd.c               \
		./srcs/func_dir/unset.c             \
		./srcs/func_dir/sh_cd_err_handle.c  \
		./srcs/func_dir/sh_cd_utils.c       \
		./srcs/func_dir/sh_change_pwd.c     \
		./srcs/func_dir/sh_two_args.c       	

CC = clang
WARNS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)

$(LIB): $(OBJ)
	@echo "Creating directory libc directory ..."
	@if [ ! -d ./libc ]; then mkdir ./libc; fi
	@echo "Every funtion is compile proved ..."
	@echo "Building libft static library ..."
	@make -C ./srcs/libft
	@ar rcs $(LIB) $(OBJ)
	@echo "All functions added to static lib ..."
	@echo "Making program executable ..."
	@$(CC) $(WARNS) ./srcs/main.c -o $(EXEC_FILE) -L./libc -lsh -lft

$(OBJ): %.o :%.c
	@echo "Check $< to be right ..."
	@$(CC) $(WARNS) -o $@ -c $<

all: $(LIB)

clean:
	@echo "Removing all binaries ..."
	@rm -rf $(OBJ)
	@echo "Removing all libft binaries"
	@make clean -C ./srcs/libft/

fclean: clean
	@echo "Removing static library ..."
	@rm -rf $(LIB)
	@rm -rf $(EXEC_FILE)
	@echo "Removing libft static library ..."
	@make fclean -C ./srcs/libft/

re: fclean all
