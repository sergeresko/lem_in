/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:50:28 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/20 19:50:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "lem_in.h"

// TODO: +/- 1 to n_turns so that it makes sense

static void		compute_ants_per_path(t_solution *s, int i)
{
	int			j;

	j = 0;
	while (j < i)
	{
		s->ants_per_path[j] = s->n_turns - s->paths[j].length;
		++j;
	}
	while (j < s->n_paths)
	{
		s->ants_per_path[j] = 0;
		++j;
	}
}

/*
**	TODO: determine how many ants should travel each path
*/

static int		distribute_evenly(int ant_count, t_solution *s)
{
	int			i;
	int			d;

	i = 1;
	while (i < s->n_paths)
	{
		d = s->paths[i].length - s->paths[i - 1].length;
		if (ant_count / i <= d)
			break ;
		ant_count -= d * i;
		++i;
	}
	d = ant_count / i;
	ant_count -= d * i;
	s->n_turns = s->paths[i - 1].length + d;
	if (s->n_turns < 0)
		error("too many ants");
	compute_ants_per_path(s, i);
	return (ant_count);
}

static void		distribute_remainder(int ant_count, t_solution *s)
{
	int			i;

	if (ant_count == 0)
		s->n_turns -= 1;
	i = 0;
	while (ant_count--)
	{
		s->ants_per_path[i] += 1;
		++i;
	}
}

void			distribute_ants(int total_ants, t_solution *s)
{
	int			remaining_ants;

	remaining_ants = distribute_evenly(total_ants, s);
	// TODO: if remaining_ants > 0
	distribute_remainder(remaining_ants, s);
}
