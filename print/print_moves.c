/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:21:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:21:02 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free
#include "libft.h"
#include "lem_in.h"

static int		add(t_room **loc, t_solution const *s)
{
	int			i;

	i = 0;
	while (i < s->n_paths && s->ants_per_path[i] > 0)
	{
		s->ants_per_path[i] -= 1;		// modifies solution, so const is misleading
		loc[i] = s->paths[i].origin;
		++i;
	}
	return (i);
}

static void		advance(t_room **loc, int k)
{
	int			i;

	i = 0;
	while (i < k)
	{
		if (loc[i] != NULL)
			loc[i] = loc[i]->best_succ;		// ->... ?
		++i;
	}
}

static void		print_turn(t_room *const *loc, int k)
{
	int			i;
	t_bool		first;

	i = 0;
	first = TRUE;
	while (i < k)
	{
		if (loc[i] != NULL)
		{
			if (!first)
				ft_putchar(' ');
			else
				first = FALSE;
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr(loc[i]->name);
		}
		++i;
	}
	if (!first)				// Are these two lines
		ft_putchar('\n');	// still needed?
}

/*
**	TODO: [Description; what `loc` is for]
*/

void			print_moves(t_solution const *s, int total_ants)
{
	t_room		**loc;
	int			count;
	int			k;

	loc = malloc(total_ants * sizeof(t_room *));		// check memory
	count = s->n_turns;
	k = 0;
	while (count--)
	{
		advance(loc, k);
		k += add(loc + k, s);
		print_turn(loc, k);
	}
	free(loc);
}
