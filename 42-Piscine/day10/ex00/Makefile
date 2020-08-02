# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 16:15:43 by lchantel          #+#    #+#              #
#    Updated: 2020/02/10 18:24:54 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c  \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c

HEADER = ./includes

all:
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar -rsc $(NAME) ./*.o
	
clean:
	/bin/rm -f ./*.o

fclean: clean
	/bin/rm -f ./$(NAME)

re: fclean all
