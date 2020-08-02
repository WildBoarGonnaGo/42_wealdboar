# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 16:32:17 by lchantel          #+#    #+#              #
#    Updated: 2020/02/13 18:00:21 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./ft_display_file

HEAD = ./include

STAT_LIB = ./ft_user_lib.a

SRC = ./src/ft_atoi.c ./src/ft_putchar_write.c \
	  ./src/ft_putstr_fd.c ./src/ft_putnbr.c ./src/ft_strlen.c \
	  ./src/ft_putchar.c ./src/ft_putstr.c ./src/ft_display_file.c\

WARN = -Wall -Wextra -Werror

all:
	gcc $(WARN) -c $(SRC) -I$(HEAD)
	ar -rc $(STAT_LIB) ./*.o
	ranlib $(STAT_LIB)
	gcc $(WARM) $(STAT_LIB) -I$(HEAD) -o $(NAME)

clean:
	rm -Rf ./*.o

fclean: clean
	rm -Rf $(STAT_LIB)
	rm -Rf $(NAME)

re: fclean all
