# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 18:53:32 by lchantel          #+#    #+#              #
#    Updated: 2020/02/13 16:04:54 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./open_c

LIB = ftlib.a

WARN = -Wall -Wextra -Werror

SRC = ./src/ft_atoi.c ./src/ft_putchar.c ./open.c \
	  ./src/ft_putnbr.c ./src/ft_putstr.c ./src/ft_oper_exec.c \
	  ./src/ft_putchar_write.c ./src/ft_putstr_fd.c \
	  ./src/ft_strlen.c

HEADER = ./includes

all:
	gcc $(WARN) -c $(SRC) -I$(HEADER)
	ar -rc $(LIB) ./*.o
	ranlib $(LIB)
	gcc $(WALL) $(LIB) -o $(NAME)

run:
	$(NAME)

clean:
	/bin/rm -f ./*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB)

re: clean all
