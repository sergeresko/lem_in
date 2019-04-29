/*
 *	(c) syeresko@student.unit.ua
 *
 *	This program outputs a lem-in map with 13 rooms where each pair of rooms,
 *	except start and end, is directly connected (i.e. it represents a complete
 *	graph without one edge).
 *
 *	The number of ants is passed as a command-line argument.
 *
 *	Compiling: `gcc complete13.c -o complete13`.
 */

#include <stdio.h>
#include <stdlib.h>

#define FORMAT_ROOM		"%c %d %d\n"
#define FORMAT_LINK		"%c-%c\n"
#define CHAR_START		'S'
#define CHAR_END		'T'

int main(int ac, char **av)
{
	if (ac != 2) {
		fprintf(stderr, "usage: ./complete13 <number_of_ants>\n");
		return -1;
	}
	printf("%d\n", atoi(av[1]));
	printf("##start\n"FORMAT_ROOM, CHAR_START, 0, 1);
	printf("##end\n"FORMAT_ROOM, CHAR_END, 0, 2);
	for (char a = 'A'; a <= 'K'; ++a) {
		printf(FORMAT_ROOM, a, (1 + a - 'A'), 0);
	}
	for (char a = 'A'; a <= 'K'; ++a) {
		printf(FORMAT_LINK, a, CHAR_START);
		printf(FORMAT_LINK, a, CHAR_END);
		for (char b = a + 1; b <= 'K'; ++b) {
			printf(FORMAT_LINK, a, b);
		}
	}
	return 0;
}
