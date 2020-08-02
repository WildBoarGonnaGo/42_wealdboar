# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 18:53:32 by lchantel          #+#    #+#              #
#    Updated: 2020/02/11 19:01:25 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./do_op

SRC = ./do_op.c ./ft_atoi.c ./ft_putchar.c ./ft_putnbr.c ./ft_putstr.c

all:
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	rm -Rf $(NAME)

fclean: clean

re: clean all
