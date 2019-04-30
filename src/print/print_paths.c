/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:09:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:23:00 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "lem_in.h"
#include "solve_general.h"

// TODO: rename
static void	print_tail(t_room const *origin)
{
	while (origin != NULL)
	{
		ft_putchar(' ');
		ft_putstr(origin->name);
		origin = origin->best_succ;		// TODO: ->...
	}
}

static void	print_path(int n_ants, t_room const *start, t_room const *origin)
{
	ft_putstr("#   ");
	ft_putnbr(n_ants);
	ft_putstr(" ant");
	if (n_ants != 1)
		ft_putchar('s');
	ft_putstr(" to path [ ");
	ft_putstr(start->name);
	print_tail(origin);
	ft_putstr(" ]\n");
}

void		print_paths(t_solution const *s, t_room const *start)
{
	int		i;

	ft_putstr("#\n#   Paths:\n#\n");
	i = 0;
	while (i < s->n_paths)
	{
		print_path(s->ants_per_path[i], start, s->paths[i].origin);
		++i;
	}
	ft_putstr("#\n");
}
