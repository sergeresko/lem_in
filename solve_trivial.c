#include "libft.h"		// for printing
#include "lem_in.h"

static void		print_paths_trivial(int total_ants, t_room const *start, t_room const *end)
{
	ft_putstr("#\n#   Paths:\n#\n");
	// TODO: number of paths: 1
	ft_putstr("#   ");
	ft_putnbr(total_ants);
	ft_putstr(" ant");
	if (total_ants != 1)
		ft_putchar('s');
	ft_putstr(" to path [ ");
	ft_putstr(start->name);
	ft_putchar(' ');
	ft_putstr(end->name);
	ft_putstr(" ]\n");
	ft_putstr("#\n");
}

static void		print_total_trivial(void)
{
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(1);
	ft_putstr("\n#\n");
}

static void		print_moves_trivial(int total_ants, t_room const *end)
{
	int			i;
	t_bool		first;

	ft_putchar('\n');
	i = 0;
	first = FALSE;
	while (i < total_ants)
	{
		if (!first)
			ft_putchar(' ');
		else
			first = FALSE;
		ft_putchar('L');
		ft_putnbr(i + 1);
		ft_putchar('-');
		ft_putstr(end->name);
		++i;
	}
}

void			solve_trivial(t_lem const *lem)
{
	if (lem->options.paths)
		print_paths_trivial(lem->total_ants, lem->graph.start, lem->graph.end);
	if (lem->options.total)
		print_total_trivial();
	if (lem->options.moves)
		print_moves_trivial(lem->total_ants, lem->graph.end);
}
