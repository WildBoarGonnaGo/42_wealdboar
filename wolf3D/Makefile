# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 04:55:09 by wealdboar         #+#    #+#              #
#    Updated: 2021/03/14 03:38:34 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ./libc/libmaze3d.a
EXEC_FILE = cub3d

# ./func_dir/cd.c => ./srcs/func_dir/cd.c

SRC =	./src/check_cub.c					\
	 	./src/check_data.c					\
		./src/check_file_ext.c				\
		./src/color_utils.c					\
		./src/colors.c						\
		./src/draw_item.c					\
		./src/err_handle.c					\
		./src/err_utils.c					\
		./src/get_next_line_bonus.c			\
		./src/get_next_line_utils_bonus.c	\
		./src/impost_map_spec.c				\
		./src/item_vars_base.c				\
		./src/keymap_interface.c			\
		./src/map_ansys.c					\
		./src/map_conf_utils.c				\
		./src/map_init_utils.c				\
		./src/map_trans_utils.c				\
		./src/mem_utils.c					\
		./src/mlx_pxl_put.c					\
		./src/raycast_exit_proc.c			\
		./src/raycast_vars_init.c			\
		./src/read_bmp_file.c				\
		./src/render_scene.c				\
		./src/render_utils.c				\
		./src/save_state.c					\
		./src/std_line.c					\
		./src/two_forked_list.c				\
		./src/write_bmp_file.c				\
		./src/max_res_config.c				\

CC = clang
WARNS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
RES_CONFIG = res_config.txt

$(LIB): $(OBJ)	
	@echo "Every funtion is compile proved ..."
	@echo "Building libft static library ..."
	@cd ./src/libft/ && make all
	@ar rcs $(LIB) $(OBJ)
	@echo "All functions added to static lib ..."
	@echo "Making program executable ..."
	@echo "Creating display resolution configuration file ..."
	@xrandr | awk 'FNR == 3 {print $1}' > $(RES_CONFIG)
	@$(CC) $(WARNS) ./main.c -o $(EXEC_FILE) -lX11 -lXext -lm -L./libc/ -lmaze3d -lmlx -lft

$(OBJ): %.o :%.c
	@echo "check $< to be right"
	@$(CC) $(WARNS) -o $@ -c $<

all: $(LIB)

clean:
	@echo "removing all binaries ..."
	@rm -rf $(OBJ)
	@echo "removing all libft binaries"
	@cd ./src/libft/ && make clean

fclean: clean
	@echo "removing static library ..."
	@rm -rf $(LIB)
	@rm -rf $(EXEC_FILE)
	@echo "removing libft static library ..."
	@cd ./src/libft/ && make fclean
	@echo "removing display resolution configuration file ..."
	@rm -rf $(RES_CONFIG)

re: fclean all

install: re clean
	@echo "coping $(LIB) to $(LIBP)"
	@sudo cp $(LIB) $(LIBP)
	@echo "coping sources to $(SRCP)"
	@sudo cp $(SRC) $(SRCP)
	@echo "coping header to $(INCLUDEP)"
	@sudo cp $(HEADER) $(INCLUDEP)
