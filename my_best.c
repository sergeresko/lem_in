#include <stdlib.h>
#include <stdio.h>

static void usage(void) {
	printf("Usage: ./my ants len1 [len2 [len3 [...]]]\n"
			"where\n"
			"    ants - number of ants (>= 1),\n"
			"    lenX - path lengths (>= 2) in non-descending order.\n");
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

	/* beginning of different part */

	// TODO: there's sometimes an off-by-one error in n_turns

	int i = 0;
	while (++i < n_paths) {
		int d = lengths[i] - lengths[i - 1];
		if (n_ants / i < d) {
			break;
		}
		n_ants -= d * i;
	}
	int d = n_ants / i;
	n_ants -= d * i;
	n_turns = lengths[i - 1] + d;
	for (int j = 0; j < i; ++j) {
		numbers[j] = n_turns - lengths[j];
	}
	for (int j = i; j < n_paths; ++j) {
		numbers[j] = 0;
	}
	for (int j = 0; n_ants; ++j, --n_ants) {
		numbers[j]++;
	}

	/* end of different part */

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
