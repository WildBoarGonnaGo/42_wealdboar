# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 10:53:46 by lchantel          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/05/14 18:30:23 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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

BONUS_SRC	= 			\
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
WARNS		= -Wall -Wextra -Werror
MAIN_OBJS	= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
HEADER_DIR	= ./
HEADER		= libft.h

$(NAME): right_prep $(HEADER)
		@ar rcs $(NAME) $(MAIN_OBJS)
		@echo "All functions added to static lib..."
		@ranlib $@

right_prep: $(MAIN_OBJS)
		@echo "Every mandatory function is compile proved!"

$(MAIN_OBJS): %.o: %.c
		@echo "checking $< to be right..."
		@$(CC) $(WARNS) -o $@ -c $<

all: $(NAME)

$(BONUS_OBJS): %.o: %.c
	@echo "checking $< to be right..."
	@$(CC) $(WARNS) -o $@ -c $<

bonus_right: $(BONUS_OBJS)
	@echo "Every bonus function is compile proved!"

bonus: bonus_right $(HEADER)
		@ar rcs $(NAME) $(BONUS_OBJS)
		@echo "Bonus functions succesfully added to static lib..."
		@ranlib $(NAME)
		
clean:
		@echo "Removing all binaries..."
		@rm -rf $(MAIN_OBJS) $(BONUS_OBJS)

fclean: clean
		@echo "Removing static lib..." 
		@rm -rf $(NAME)
=======
#    Updated: 2020/05/11 15:17:35 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

WARN = -Wall -Wextra -Werror

SRC = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c \
      ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c \
	 ./ft_strlcpy.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c \
	 ./ft_strnstr.c ./ft_strncmp.c ./ft_isdigit.c ./ft_atoi.c \
	 ./ft_isalpha.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c \
	 ./ft_tolower.c ./ft_toupper.c ./ft_calloc.c ./ft_strdup.c \
	 ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c \
	 ./ft_itoa.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
	 ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_lstmap.c 

CC = gcc

BONUS = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c \
		./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

$(NAME):
	$(CC) $(WARN) -c $(SRC) -I .
	ar -rc ./$(NAME).a $(OBJ)
	ranlib ./$(NAME).a 

all: $(NAME)

bonus:
	$(CC) $(WARN) -c $(BONUS) -I .
	ar -r ./$(NAME).a $(OBJ_BONUS)
	ranlib ./$(NAME).a

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf ./$(NAME).a
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26

re: fclean all

