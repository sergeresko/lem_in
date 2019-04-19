#include <stdlib.h>
#include <stdio.h>

static void usage(void) {
	printf("Usage: ./their ants len1 [len2 [len3 [...]]]\n"
	"where\n"
	"    ants - number of ants (>= 1),\n"
	"    lenX - path lengths (>= 2) in non-decreasing order (with another order\n"
	"			the answer may be incorrect if some paths are unused).\n");
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

	int debug_iterations = 0;		//
	while (n_ants) {
		int i = 0;
		while (++debug_iterations && i < n_paths - 1
				&& lengths[i] + numbers[i] >= lengths[i + 1] + numbers[i + 1]) {
			++i;
		}
		numbers[i]++;
		--n_ants;
	}
	printf("[debug: iterations = %d]\n", debug_iterations);		//

	n_turns = 0;
	for (int i = 0; i < n_paths; ++i) {
		if (numbers[i]) {
			int tmp = numbers[i] + lengths[i] - 1;
			if (tmp > n_turns)
				n_turns = tmp;
		}
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
