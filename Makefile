# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 19:29:13 by syeresko          #+#    #+#              #
#    Updated: 2019/04/27 15:56:06 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a

# -----------------------------------------------------------------------------

FILES_C		+=	$(addprefix lem_in/, \
					main.c \
					read_options.c \
					read_input.c \
					solve_instant.c \
					solve_trivial.c \
					solve_general.c \
				)
FILES_C		+=	$(addprefix read_input/, \
					get_next_token.c \
					read_ants.c \
					read_rooms.c \
					read_links.c \
				)
# NOTE: `read_turns.c` is not needed in for `lem-in`
FILES_C		+=	$(addprefix get_next_token/, \
					ft_atoi_strict.c \
					tokenize_turn.c \
					tokenize.c \
				)
FILES_C		+=	$(addprefix solve_general/, \
					find_more_paths.c \
					distribute_ants.c \
					build_solution.c \
					improve_solution.c \
					destroy_solution.c \
				)
FILES_C		+=	$(addprefix find_more_paths/, \
					modify_graph.c \
					find_shortest_path.c \
					restore_graph.c \
					combine_paths.c \
				)
FILES_C		+=	$(addprefix print/, \
					print_input.c \
					print_rooms.c \
					print_paths.c \
					print_total.c \
					print_moves.c \
				)
FILES_C		+=	$(addprefix datatypes/, \
					list.c \
					room.c \
					link.c \
					set.c \
				)
FILES_C		+=	$(addprefix error/, \
					error.c \
				)

# -----------------------------------------------------------------------------

SRC			=	$(addprefix $(SRC_DIR), $(FILES_C))
OBJ			=	$(addprefix $(OBJ_DIR), $(FILES_C:%.c=%.o))

# -----------------------------------------------------------------------------

# linking (do we need flags here?)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

# -----------------------------------------------------------------------------

# compiling

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)

# -----------------------------------------------------------------------------

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# -----------------------------------------------------------------------------

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
