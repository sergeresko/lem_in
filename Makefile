gcc -Wall -Wextra -Werror \
	_test/test_read.c \
	-I . -I read_input -I ~/projects/filler/rendu/libft \
	~/projects/filler/rendu/libft/libft.a \
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
