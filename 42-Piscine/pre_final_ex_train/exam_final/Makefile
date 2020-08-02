# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:50:01 by lchantel          #+#    #+#              #
#    Updated: 2020/02/20 23:07:21 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maff_alpha

SRC = ./$(NAME)/*.c

WARN = -Wall -Wextra -Werror

prep:
	mkdir ./$(NAME)
	touch ./$(NAME)/$(NAME).en.txt
	touch ./$(NAME)/$(NAME).c

compile:
	gcc $(WARN) $(SRC) -o $(NAME).exe

clean:
	rm -Rf $(NAME).exe

fclean: clean

re: fclean all
