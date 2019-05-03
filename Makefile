# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 19:29:13 by syeresko          #+#    #+#              #
#    Updated: 2019/05/03 15:59:33 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN		=	lem-in
VERIFIER	=	verifier
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# --------- Header files ------------------------------------------------------

INC			=	$(addprefix inc/,					\
					lem_in.h						\
					read_input.h					\
					get_next_token.h				\
					datatypes.h						\
					error.h							\
					solve_general.h					\
					find_more_paths.h				\
					print.h							\
				)

# --------- Source files ------------------------------------------------------

SRC_LEMIN	=	$(addprefix src/lem_in/,			\
					main.c							\
					read_options.c					\
					read_input.c					\
					solve_instant.c					\
					solve_trivial.c					\
					solve_general.c					\
				)
SRC_VERIF	=	$(addprefix src/verifier/,			\
					main.c							\
					read_options.c					\
					read_input.c					\
				)
SRC_RDINP_L	=	$(addprefix src/read_input/,		\
					get_next_token.c				\
					read_ants.c						\
					read_rooms.c					\
					read_links.c					\
				)
SRC_RDINP_V	=	$(SRC_RDINP_L) 						\
				$(addprefix src/read_input/,		\
					read_turns.c					\
				)
SRC_GNTOK	=	$(addprefix src/get_next_token/,	\
					ft_atoi_strict.c				\
					tokenize_turn.c					\
					tokenize.c						\
				)
SRC_DTYPS	=	$(addprefix src/datatypes/,			\
					list.c							\
					room.c							\
					link.c							\
					set.c							\
				)
SRC_ERROR	=	$(addprefix src/error/,				\
					error.c							\
				)
SRC_SLVGN	=	$(addprefix src/solve_general/,		\
					find_more_paths.c				\
					distribute_ants.c				\
					solution_build.c				\
					solution_improve.c				\
					solution_destroy.c				\
				)
SRC_FMPTH	=	$(addprefix src/find_more_paths/,	\
					modify_graph.c					\
					find_shortest_path.c			\
					restore_graph.c					\
					combine_paths.c					\
				)
SRC_PRINT_V	=	$(addprefix src/print/,				\
					print_input.c					\
				)
SRC_PRINT_L	=	$(SRC_PRINT_V)						\
				$(addprefix src/print/,				\
					print_rooms.c					\
					print_total.c					\
					print_path.c					\
					print_moves.c					\
				)

# --------- Object files ------------------------------------------------------

OBJ_L		=	$(patsubst src/%.c, obj/%.o,		\
					$(SRC_LEMIN)					\
					$(SRC_RDINP_L)					\
					$(SRC_GNTOK)					\
					$(SRC_DTYPS)					\
					$(SRC_ERROR)					\
					$(SRC_SLVGN)					\
					$(SRC_FMPTH)					\
					$(SRC_PRINT_L)					\
				)
OBJ_V		=	$(patsubst src/%.c, obj/%.o,		\
					$(SRC_VERIF)					\
					$(SRC_RDINP_V)					\
					$(SRC_GNTOK)					\
					$(SRC_DTYPS)					\
					$(SRC_ERROR)					\
					$(SRC_PRINT_V)					\
				)

# --------- Phony targets -----------------------------------------------------

.PHONY: all clean fclean re

all: $(LEMIN) $(VERIFIER)

clean:
	@ rm -f $(OBJ_L) $(OBJ_V)
	@ make clean -sC libft/
	@ echo "Object files removed"

fclean: clean
	@ rm -rf obj/
	@ rm -f $(LEMIN) $(VERIFIER)
	@ make fclean -sC libft/
	@ echo "Binaries and library removed"

re: fclean all

# --------- Linking -----------------------------------------------------------

$(LEMIN): $(LIBFT) $(OBJ_L)
	@ mkdir -p obj/
	@ printf "%-60s\n" "Linking $@"
	@ $(CC) -o $(LEMIN) $(OBJ_L) $(LIBFT)
	@ echo "Done"

$(VERIFIER): $(LIBFT) $(OBJ_V)
	@ mkdir -p obj/
	@ printf "%-60s\n" "Linking $@"
	@ $(CC) -o $(VERIFIER) $(OBJ_V) $(LIBFT)
	@ echo "Done"

$(LIBFT):
	@ echo "Building $@"
	@ make -sC libft/
	@ echo "Done"

# --------- Compiling ---------------------------------------------------------

obj/%.o: src/%.c $(INC) libft/libft.h
	@ mkdir -p $(dir $@)
	@ printf "%-60s\r" "Compiling $<"
	@ $(CC) $(CFLAGS) -o $@ -c $< -I inc/ -I libft/
