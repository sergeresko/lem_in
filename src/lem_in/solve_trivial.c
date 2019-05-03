/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_trivial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:10:49 by syeresko          #+#    #+#             */
/*   Updated: 2019/05/03 19:10:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "print.h"

static void		print_paths_trivial(t_lem const *lem)
{
	print_total("paths", 1);
	print_path(lem->total_ants, 1, lem->graph.start, lem->graph.end);
	ft_putstr("#\n");
}

static void		print_moves_trivial(t_lem const *lem)
{
	char *const	end_name = lem->graph.end->name;
	int			i;
	t_bool		first;

	ft_putchar('\n');
	i = 0;
	first = TRUE;
	while (i < lem->total_ants)
	{
		if (!first)
			ft_putchar(' ');
		else
			first = FALSE;
		ft_putchar('L');
		ft_putnbr(i + 1);
		ft_putchar('-');
		ft_putstr(end_name);
		++i;
	}
	ft_putchar('\n');
}

void			solve_trivial(t_lem const *lem)
{
	if (lem->options.paths)
		print_paths_trivial(lem);
	if (lem->options.turns)
		print_total("turns", 1);
	if (lem->options.moves)
		print_moves_trivial(lem);
}
