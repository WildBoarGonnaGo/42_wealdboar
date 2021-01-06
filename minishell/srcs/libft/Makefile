# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 10:53:46 by lchantel          #+#    #+#              #
#    Updated: 2021/01/06 18:59:19 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../libc/libft.a

SRC = ft_atoi.c			\
	ft_bzero.c			\
	ft_isalnum.c		\
	ft_isalpha.c		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_itoa.c			\
	ft_memccpy.c		\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_memset.c			\
	ft_putchar_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_putstr_fd.c		\
	ft_split.c			\
	ft_strchr.c			\
	ft_strdup.c			\
	ft_strjoin.c		\
	ft_strlcat.c		\
	ft_strlcpy.c		\
	ft_strlen.c			\
	ft_strmapi.c		\
	ft_strncmp.c		\
	ft_strnstr.c		\
	ft_strrchr.c		\
	ft_strtrim.c		\
	ft_substr.c			\
	ft_tolower.c		\
	ft_toupper.c		\
	ft_calloc.c			\
	ft_lstnew.c			\
	ft_lstadd_front.c	\
	ft_lstsize.c		\
	ft_lstlast.c		\
	ft_lstadd_back.c	\
	ft_lstdelone.c		\
	ft_lstclear.c		\
	ft_lstiter.c		\
	ft_lstmap.c			\

CC			= clang
WARNS		= -Wall -Wextra -Werror -g
MAIN_OBJS	= $(SRC:.c=.o)
HEADER		= libft.h

$(NAME): $(HEADER) $(MAIN_OBJS) $(BONUS_OBJS)
	@echo "Every function is compile proved!"
	@ar rcs $(NAME) $(MAIN_OBJS) $(BONUS_OBJS)
	@echo "All functions added to static lib..."

$(MAIN_OBJS): %.o: %.c $(HEADER)
	@echo "checking $< to be right..."
	@$(CC) $(WARNS) -o $@ -c $<

all: $(NAME)

clean:
	@echo "Removing all binaries..."
	@rm -rf $(MAIN_OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "Removing static lib..." 
	@rm -rf $(NAME)

re: fclean all

