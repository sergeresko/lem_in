# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 14:52:25 by syeresko          #+#    #+#              #
#    Updated: 2019/04/26 20:03:25 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = \
	ft_memcpy.c \
	\
	ft_strlen.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	\
	ft_strsub.c ft_strjoin.c \
	ft_strsplit.c \
	\
	ft_clear_tab.c \
	\
	ft_putchar.c ft_putchar_fd.c \
	ft_putstr.c ft_putstr_fd.c \
	ft_putnbr.c ft_putnbr_fd.c \
	\
	get_next_line.c \
	\
	ft_malloc_or_die.c

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c libft.h
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
