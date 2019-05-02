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

#include <stdlib.h>
#include "libft.h"
#include "solve_general.h"

/*
**	CAUTION: This function modifies values strored in `solution->ants_per_path`
**		so `const` qualifier is misleading.
*/

static int		release_ants(t_room **loc, t_solution const *solution)
{
	int			i;

	i = 0;
	while (i < solution->n_paths && solution->ants_per_path[i] > 0)
	{
		solution->ants_per_path[i] -= 1;
		loc[i] = solution->paths[i].origin;
		++i;
	}
	return (i);
}

static void		advance_ants(t_room **loc, int limit)
{
	int			i;

	i = 0;
	while (i < limit)
	{
		if (loc[i] != NULL)
			loc[i] = loc[i]->best_succ;		// ->... ?
		++i;
	}
}

static void		print_turn(t_room *const *loc, int limit)
{
	int			i;
	t_bool		first;

	i = 0;
	first = TRUE;
	while (i < limit)
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
	if (!first)
		ft_putchar('\n');
}

/*
**	TODO: [Description; what `loc` is for]
*/

void			print_moves(t_solution const *solution, int total_ants)
{
	t_room		**loc;
	int			count;
	int			limit;

	loc = ft_malloc_or_die(total_ants * sizeof(t_room *));
	count = solution->n_turns;
	limit = 0;
	ft_putchar('\n');
	while (count--)
	{
		advance_ants(loc, limit);
		limit += release_ants(loc + limit, solution);
		print_turn(loc, limit);
	}
	free(loc);
}
