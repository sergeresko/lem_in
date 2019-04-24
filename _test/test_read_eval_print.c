#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_lem		lem;
	t_solution	*s;
	int			n_paths;

	read_options(argc, argv, &lem.options);
	read_input(&lem);
	if (lem.options.input)
		print_input(&lem.input);
	if (lem.options.rooms)
		print_rooms(&lem.graph);

	if (link_find(lem.graph.start, lem.graph.end) != NULL)
	{
		ft_putstr("TODO: start and end are directly connected\n");
		return (0);
	}

	n_paths = 0;
	while (bhandari(&lem.graph))
	{
		++n_paths;
		s = build_solution(lem.total_ants, lem.graph.start, n_paths);
		if (lem.options.paths)
			print_paths(s, lem.graph.start);
		if (lem.options.moves)
			print_solution(s, lem.total_ants);
		if (lem.options.total)
			print_total(s);
		solution_destroy(s);
	}

	system("leaks -q a.out");

	return (0);
}
