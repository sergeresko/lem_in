#LIBFT_DIR=~/projects/filler/rendu/libft/
LIBFT_DIR='../filler/test/libft/'

gcc -g -Wall -Wextra -Werror \
	_test/test_read_eval_print.c \
	-I ./ -I read_input/ -I ../filler/test/libft/ \
	\
	read_options.c \
	\
	read_input/find_room.c \
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
	algorithm/bhandari.c \
	algorithm/modify_graph.c \
	algorithm/restore_graph.c \
	algorithm/xor_paths.c \
	\
	algorithm/dijkstra.c \
	\
	algorithm/build_solution.c \
	algorithm/distribute_ants.c \
	\
	print_input.c \
	print_rooms.c \
	print_paths.c \
	print_solution.c \
	print_total.c \
	\
	-L ../filler/test/libft/ -l ft
