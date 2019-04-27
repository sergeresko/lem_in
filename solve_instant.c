#include "libft.h"		// for printing
#include "lem_in.h"

// These static functions are not actually needed as they can be inlined.

static void		print_paths_instant(void)
{
	ft_putstr("#\n#   Paths:\n#\n");
	// TODO: number of paths: 0
	ft_putstr("#\n");
}

static void		print_moves_instant(void)
{
	ft_putstr("\n");	// TODO: ?
}

static void		print_total_instant(void)
{
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(0);
	ft_putstr("\n#\n");
}

// if there are zero ants
void			solve_instant(t_lem const *lem)
{
	// TODO: reorder, empty line
	if (lem->options.paths)
		print_paths_instant();
	if (lem->options.moves)
		print_moves_instant();
	if (lem->options.total)
		print_total_instant();
}
