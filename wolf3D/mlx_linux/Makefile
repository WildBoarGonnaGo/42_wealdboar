# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 04:55:09 by wealdboar         #+#    #+#              #
#    Updated: 2020/08/24 21:45:44 by wealdboar        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libgeoms.a

SRC =	mlx_pxl_put.c	\
	 	std_arc.c		\
		std_crcl.c		\
		std_line.c		\
		std_poly.c		\
		std_rect.c		\

CC = clang
WARNS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRCP = /usr/local/wealdboar/src/
INCLUDEP = /usr/local/wealdboar/include/
LIBP = /usr/local/wealdboar/lib/
HEADER = geoms.h

$(LIB): $(OBJ)
	@echo "Every funtion is compile proved ..."
	@ar rcs $(LIB) $(OBJ)
	@echo  "All functions added to static lib ..."

$(OBJ): %.o :%.c
	@echo "check $< to be right"
	@$(CC) $(WARNS) -o $@ -c $<

all: $(LIB)

clean:
	@echo "removing all binaries ..."
	@rm -rf $(OBJ)

fclean: clean
	@echo "removing static library ..."
	@rm -rf $(LIB)

re: fclean all

install: re clean
	@echo "coping $(LIB) to $(LIBP)"
	@sudo cp $(LIB) $(LIBP)
	@echo "coping sources to $(SRCP)"
	@sudo cp $(SRC) $(SRCP)
	@echo "coping header to $(INCLUDEP)"
	@sudo cp $(HEADER) $(INCLUDEP)
