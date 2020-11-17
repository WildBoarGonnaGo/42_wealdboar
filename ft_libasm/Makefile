# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 04:55:09 by wealdboar         #+#    #+#              #
#    Updated: 2020/11/17 22:00:35 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB =		./lib/libasm.a
EXEC_FILE =	cub3d

SRC =		./libasm_linux-amd64/ft_read.s						\
	 		./libasm_linux-amd64/ft_strcmp.s					\
			./libasm_linux-amd64/ft_strcpy.s					\
			./libasm_linux-amd64/ft_strdup.s					\
			./libasm_linux-amd64/ft_strlen.s					\
			./libasm_linux-amd64/ft_write.s						\

BONUS_SRC = ./libasm_linux-amd64/ft_atoi_base_bonus.s			\
			./libasm_linux-amd64/ft_list_push_front_bonus.s		\
			./libasm_linux-amd64/ft_list_size_bonus.s			\

ASM = nasm
FLAGS = -f elf64 -F dwarf -g
OBJ = $(SRC:.s=.o)
BONUS_OBJ = $(BONUS_SRC:.s=.o)

$(LIB): $(OBJ)	
	@echo "Every funtion is compile proved ..."
	@ar rcs $(LIB) $(OBJ)
	@echo "All functions added to static lib ..."

$(OBJ): %.o :%.s
	@echo "check $< to be right"
	@$(ASM) $(FLAGS) $< -o $@ 

all: $(LIB)

clean:
	@echo "removing all binaries ..."
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@echo "removing all bonus binaries ..."

bonus: $(BONUS_OBJ)
	@echo "Every funtion is compile proved ..."
	@ar rs $(LIB) $(BONUS_OBJ)
	@echo "All functions added to static lib ..."

$(BONUS_OBJ): %.o :%.s
	@echo "check $< to be right"
	@$(ASM) $(FLAGS) $< -o $@ 

fclean: clean
	@echo "removing static library ..."
	@rm -rf $(LIB)

re: fclean all
