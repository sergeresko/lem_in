# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 19:29:13 by syeresko          #+#    #+#              #
#    Updated: 2019/04/26 16:28:14 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ~/projects/filler/rendu/libft/
#LIBFT_DIR = ../filler/test/libft/

NAME = a.out

all: $(NAME)

$(NAME):
	@ gcc -Wall -Wextra -Werror \
		_test/test_read_eval_print.c \
		-I ./ -I read_input/ -I datatypes/ -I find_more_paths/ -I $(LIBFT_DIR) \
		\
		read_options.c \
		\
		read_input/ft_atoi_strict.c \
		read_input/tokenize.c \
		read_input/get_next_token.c \
		read_input/read_ants.c \
		read_input/read_rooms.c \
		read_input/read_links.c \
		read_input/read_input.c \
		\
		lem_die.c \
		\
		datatypes/glist.c \
		datatypes/link.c \
		datatypes/room.c \
		datatypes/set.c \
		\
		find_more_paths/find_more_paths.c \
		find_more_paths/modify_graph.c \
		find_more_paths/find_shortest_path.c \
		find_more_paths/restore_graph.c \
		find_more_paths/xor_paths.c \
		\
		solution/build_solution.c \
		solution/distribute_ants.c \
		\
		print/print_input.c \
		print/print_rooms.c \
		print/print_paths.c \
		print/print_moves.c \
		print/print_total.c \
		\
		$(LIBFT_DIR)libft.a
