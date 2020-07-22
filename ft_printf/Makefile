# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 10:53:46 by lchantel          #+#    #+#              #
#    Updated: 2020/07/22 21:45:33 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./srcs/ft_atoi.c			\
	./srcs/ft_bzero.c			\
	./srcs/ft_isalnum.c		\
	./srcs/ft_isalpha.c		\
	./srcs/ft_isascii.c		\
	./srcs/ft_isdigit.c		\
	./srcs/ft_isprint.c		\
	./srcs/ft_itoa.c			\
	./srcs/ft_memccpy.c		\
	./srcs/ft_memchr.c			\
	./srcs/ft_memcmp.c			\
	./srcs/ft_memcpy.c			\
	./srcs/ft_memmove.c		\
	./srcs/ft_memset.c			\
	./srcs/ft_putchar_fd.c		\
	./srcs/ft_putendl_fd.c		\
	./srcs/ft_putnbr_fd.c		\
	./srcs/ft_putstr_fd.c		\
	./srcs/ft_split.c			\
	./srcs/ft_strchr.c			\
	./srcs/ft_strdup.c			\
	./srcs/ft_strjoin.c		\
	./srcs/ft_strlcat.c		\
	./srcs/ft_strlcpy.c		\
	./srcs/ft_strlen.c			\
	./srcs/ft_strmapi.c		\
	./srcs/ft_strncmp.c		\
	./srcs/ft_strnstr.c		\
	./srcs/ft_strrchr.c		\
	./srcs/ft_strtrim.c		\
	./srcs/ft_substr.c			\
	./srcs/ft_tolower.c		\
	./srcs/ft_toupper.c		\
	./srcs/ft_calloc.c			\
	./srcs/ft_lstnew.c			\
	./srcs/ft_lstadd_front.c	\
	./srcs/ft_lstsize.c		\
	./srcs/ft_lstlast.c		\
	./srcs/ft_lstadd_back.c	\
	./srcs/ft_lstdelone.c		\
	./srcs/ft_lstclear.c		\
	./srcs/ft_lstiter.c		\
	./srcs/ft_lstmap.c			\
	./srcs/ft_itoa_base.c	\
	./srcs/ft_var_putstr_fd.c	\
	./srcs/ft_utoa.c	\
	./srcs/ft_mem_reset.c	\
	./srcs/ft_mem_reset_arg.c	\
	./srcs/ft_putunbr_fd.c	\
	./srcs/ft_str_toupper.c	\
	./srcs/ft_charjoin.c	\
	./srcs/ft_integer_handle.c	\
	./srcs/ft_string_handle.c	\
	./srcs/ft_char_handle.c	\
	./srcs/ft_hexadec_handle.c	\
	./srcs/ft_spec_chars_handle.c	\
	./srcs/ft_printf_manager.c	\
	./srcs/ft_print_spaces.c	\
	./srcs/ft_printf.c	\
	./srcs/ft_putchar_fd_len.c	\
	./srcs/ft_putunbr_fd_len.c	\
	./srcs/ft_putnbr_fd_len.c	\
	./srcs/ft_putstr_fd_len.c	\
	
CC			= clang
WARNS		= -Wall -Wextra -Werror
MAIN_OBJS	= $(SRC:.c=.o)
HEADER		= ./include/ft_printf_out.h

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
	@rm -rf $(MAIN_OBJS)

fclean: clean
	@echo "Removing static lib..." 
	@rm -rf $(NAME)

re: fclean all

