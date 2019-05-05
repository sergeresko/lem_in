/*
 *	(c) 2019 syeresko@student.unit.ua
 *
 *	This program computes an optimal distribution of a given number of ants
 *	between a set of non-overlapping paths of given lengths.
 *
 *	Compiling: `gcc ant_calc.c -o ant-calc`
 */

#include <stdlib.h>
#include <stdio.h>

#define U		"\033[4m"
#define R		"\033[0m"
#define USAGE	"usage: ./ant-calc " U "ants" R \
				" " U "len1" R " [" U "len2" R " [" U "len3" R " [...]]]\n" \
				"where\n" \
				"    " U "ants" R " - number of ants (>= 1),\n" \
				"    " U "lenX" R " - path lengths (>= 2).\n"

typedef struct	s_path {
	int		id;
	int		length;
	int		ants;
}				t_path;

int			main(int ac, char **av)
{
	int		path_count;
	int		ant_count;
	t_path	*paths;
	int		turn_count;

	if ((path_count = ac - 2) < 1 || (ant_count = atoi(*++av)) < 1) {
		fprintf(stderr, USAGE);
		return 1;
	}

	if ((paths = malloc(path_count * sizeof(t_path))) == NULL) {
		fprintf(stderr, "Not enough memory\n");
		return 1;
	}

	/* initialize paths */

	for (int i = 0; i < path_count; ++i) {
		paths[i].id = i;
		if ((paths[i].length = atoi(*++av)) < 2) {
			fprintf(stderr, USAGE);
		}
	}

	/* sort paths by length */

	for (int i = 0; i < path_count - 1; ++i) {
		for (int j = i + 1; j < path_count; ++j) {
			if (paths[i].length > paths[j].length) {
				t_path const path = paths[i];
				paths[i] = paths[j];
				paths[j] = path;
			}
		}
	}

	/* compute the distribution and number of turns */

	int i = 0;
	while (++i < path_count) {
		int const diff = paths[i].length - paths[i - 1].length;
		if (ant_count / i <= diff) {
			break;
		}
		ant_count -= diff * i;
	}
	int const diff = ant_count / i;
	ant_count -= diff * i;
	turn_count = paths[i - 1].length + diff - 1;
	if (turn_count < 0) {
		fprintf(stderr, "Overflow\n");
		return 1;
	}

	for (int j = 0; j < i; ++j) {
		paths[j].ants = turn_count - paths[j].length + 1;
	}
	for (int j = i; j < turn_count; ++j) {
		paths[j].ants = 0;
	}

	if (ant_count) {
		turn_count += 1;
	}
	for (int i = 0; i < ant_count; ++i) {
		paths[i].ants += 1;
	}

	/* restore initial order */

	for (int i = 0; i < path_count - 1; ++i) {
		for (int j = i + 1; j < path_count; ++j) {
			if (paths[i].id > paths[j].id) {
				t_path const path = paths[i];
				paths[i] = paths[j];
				paths[j] = path;
			}
		}
	}

	/* display */

	printf("       length    ants\n");
	for (int i = 0; i < path_count; ++i) {
		printf("%3d. %7d %7d\n", i + 1, paths[i].length, paths[i].ants);
	}
	printf("turns: %d\n", turn_count);

	return 0;
}
