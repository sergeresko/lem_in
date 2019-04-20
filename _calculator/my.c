#include <stdlib.h>
#include <stdio.h>

static void usage(void) {
	printf("Usage: ./my ants len1 [len2 [len3 [...]]]\n"
			"where\n"
			"    ants - number of ants (>= 1),\n"
			"    lenX - path lengths (>= 2).\n");
	exit(1);
}

static void memory(void) {
	printf("Not enough memory.\n");
	exit(1);
}

int main(int ac, char **av) {
	int n_ants;
	int n_paths;
	int *lengths;
	int *numbers;
	int n_turns;

	if ((n_paths = ac - 2) < 1 || (n_ants = atoi(*++av)) < 1) {
		usage();
	}

	if ((lengths = malloc(n_paths * sizeof(int))) == NULL ||
		(numbers = malloc(n_paths * sizeof(int))) == NULL) {
		memory();
	}

	for (int i = 0; i < n_paths; ++i) {
		if ((lengths[i] = atoi(*++av)) < 2) {
			usage();
		}
		numbers[i] = 0;
	}

	printf("Lenghts:\n");
	printf("[%d]=%d", 0, lengths[0]);
	for (int i = 1; i < n_paths; ++i) {
		printf(", [%d]=%d", i, lengths[i]);
	}
	printf("\n");

	int debug_iterations = 0;		//
	n_turns = 0;
	while (n_ants) {
		++n_turns;
		for (int i = 0; i < n_paths; ++i) {
			++debug_iterations;		//
			if (lengths[i]) {
				lengths[i]--;
			}
			if (lengths[i] == 0) {
				numbers[i]++;
				if (--n_ants == 0) {
					break;
				}
			}
		}
	}
	printf("[debug: iterations = %d]\n", debug_iterations);		//

	printf("Numbers:\n");
	printf("[%d]=%d", 0, numbers[0]);
	for (int i = 1; i < n_paths; ++i) {
		printf(", [%d]=%d", i, numbers[i]);
	}
	printf("\n");
	printf("Turns: %d\n", n_turns);

	free(lengths);
	free(numbers);

	return 0;
}
