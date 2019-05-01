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

#NAME_L		=	lem-in
#NAME_V		=	verifier

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

#INC_DIR		=	inc/
#SRC_DIR		=	src/
#OBJ_DIR		=	obj/

#LIBFT_DIR	=	libft/
LIBFT		=	libft/libft.a

# -----------------------------------------------------------------------------

LEMIN_H		=	inc/lem_in.h
LEMIN_C		=	$(addprefix src/lemin/, \
					main.c \
					read_options.c \
					read_input.c \
					solve_instant.c \
					solve_trivial.c \
					solve_general.c)
LEMIN_O		=	$(LEMIN_C:src/%.c=obj/%.o)

VERIF_C		=	$(addprefix src/verifier/, \
					main.c \
					read_input.c)
VERIF_O		=	$(VERIF_C:src/%.c=obj/%.o)

RDINP_H		=	inc/read_input.h
RDINP_L_C	=	$(addprefix src/read_input/, \
					get_next_token.c \
					read_ants.c \
					read_rooms.c \
					read_links.c)
RDINP_V_C	=	$(RDINP_L_C) \
				$(addprefix src/read_input/, \
					read_turns.c)
RDINP_L_O	=	$(RDINP_L_C:src/%.c=obj/%.o)
RDINP_V_O	=	$(RDINP_V_C:src/%.c=obj/%.o)

GNTOK_H		=	inc/get_next_token.h
GNTOK_C		=	$(addprefix src/get_next_token/, \
					ft_atoi_strict.c \
					tokenize_turn.c \
					tokenize.c)
GNTOK_O		=	$(GNTOK_C:src/%.c=obj/%.o)

SLVGN_H		=	inc/solve_general.h
SLVGN_C		=	$(addprefix src/solve_general/, \
					find_more_paths.c \
					distribute_ants.c \
					build_solution.c \
					improve_solution.c \
					destroy_solution.c)
SLVGN_O		=	$(SLVGN_C:src/%.c=obj/%.o)

FMPAT_H		=	inc/find_more_paths.h
FMPAT_C		=	$(addprefix src/find_more_paths/, \
					modify_graph.c \
					find_shortest_path.c \
					restore_graph.c \
					combine_paths.c)
FMPAT_O		=	$(FMPAT_C:src/%.c=obj/%.o)

PRINT_H		=	inc/print.h
PRINT_C		=	$(addprefix src/print/, \
					print_input.c \
					print_rooms.c \
					print_paths.c \
					print_total.c \
					print_moves.c)
PRINT_O		=	$(PRINT_C:src/%.c=obj/%.o)

DTYPS_H		=	inc/datatypes.h
DTYPS_C		=	$(addprefix src/datatypes/, \
					list.c \
					room.c \
					link.c \
					set.c)
DTYPS_O		=	$(DTYPS_C:src/%.c=obj/%.o)

ERROR_H		=	inc/error.h
ERROR_C		=	$(addprefix src/error/, \
					error.c)
ERROR_O		=	$(ERROR_C:src/%.c=obj/%.o)

# -----------------------------------------------------------------------------

INC			=	$(LEMIN_H) $(RDINP_H) $(GNTOK_H) $(DTYPS_H) $(ERROR_H) \
				$(SLVGN_H) $(FMPAT_H) $(PRINT_H)

OBJ_L		=	$(LEMIN_O) $(RDINP_L_O) $(GNTOK_O) $(DTYPS_O) $(ERROR_O) \
				$(SLVGN_O) $(FMPAT_O) $(PRINT_O)

OBJ_V		=	$(VERIF_O) $(RDINP_V_O) $(GNTOK_O) $(DTYPS_O) $(ERROR_O)

#SRC			=	$(addprefix $(SRC_DIR), $(FILES_C))
#OBJ			=	$(addprefix $(OBJ_DIR), $(FILES_C:%.c=%.o))

# -----------------------------------------------------------------------------

# linking (do we need flags here?)

lem-in: obj/ $(OBJ_L) $(LIBFT)
	$(CC) -o lem-in $(OBJ_L) $(LIBFT)

verifier: obj/ $(OBJ_V) $(LIBFT)
	$(CC) -o verifier $(OBJ_V) $(LIBFT)

# -----------------------------------------------------------------------------

# compiling

obj/%.o: src/%.c $(INC) libft/libft.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< -I inc/ -I libft/

# -----------------------------------------------------------------------------

#$(OBJ): | $(OBJ_DIR)

obj/:
	mkdir -p obj/

$(LIBFT):
	make -C libft/

# -----------------------------------------------------------------------------

all: lem-in verifier

clean:
	rm -f $(OBJ_L)
	rm -f $(OBJ_V)
	make clean -C libft/

fclean: clean
	rm -rf obj/
	rm -f lem-in verifier
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
