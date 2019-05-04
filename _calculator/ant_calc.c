#include <stdlib.h>
#include <stdio.h>

#define U	"\033[4m"
#define R	"\033[0m"

static void usage(void) {
	printf("usage: ./ant-calc "U "ants"R
			" "U "len1"R " ["U "len2"R " ["U "len3"R " [...]]]\n"
			"where\n"
			"    "U "ants"R " - number of ants (>= 1),\n"
			"    "U "lenX"R " - path lengths (>= 2).\n");
	exit(1);
}

static void memory(void) {
	printf("Not enough memory.\n");
	exit(1);
}

static void overflow(void) {
	printf("Overflow\n");
	exit(1);
}

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
		usage();
	}

	if ((paths = malloc(path_count * sizeof(t_path))) == NULL) {
		memory();
	}

	/* initialize paths */

	for (int i = 0; i < path_count; ++i) {
		paths[i].id = i;
		if ((paths[i].length = atoi(*++av)) < 2) {
			usage();
		}
	}

	/* sort paths by length */

	for (int i = 0; i < path_count - 1; ++i) {
		for (int j = i + 1; j < path_count; ++j) {
			if (paths[i].length > paths[j].length)
			{
				t_path path = paths[i];
				paths[i] = paths[j];
				paths[j] = path;
			}
		}
	}

	/* */

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
		overflow();
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
				t_path path = paths[i];
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
