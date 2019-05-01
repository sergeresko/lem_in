/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_trivial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:10:49 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:10:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		// for printing
#include "lem_in.h"
#include "print.h"

static void		print_paths_trivial(int total_ants, t_room const *start, t_room const *end)
{
	print_total("paths", 1);
	print_path(total_ants, 1, start, end);
	ft_putstr("#\n");		// TODO:
	/*
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
	*/
}

static void		print_total_trivial(void)
{
	print_total("turns", 1);
	/*
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(1);
	ft_putstr("\n#\n");
	*/
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
