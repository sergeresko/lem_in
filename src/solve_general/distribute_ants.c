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
#include "solve_general.h"
//#include "lem_in.h"
#include "error.h"

// TODO: +/- 1 to n_turns so that it makes sense

static void		compute_ants_per_path(t_solution *solution, int i)
{
	int			j;

	j = 0;
	while (j < i)
	{
		solution->ants_per_path[j] =
				solution->n_turns - solution->paths[j].length;
		++j;
	}
	while (j < solution->n_paths)
	{
		solution->ants_per_path[j] = 0;
		++j;
	}
}

/*
**	TODO: determine how many ants should travel each path
*/

static int		distribute_evenly(int ant_count, t_solution *solution)
{
	int			i;
	int			d;

	i = 1;
	while (i < solution->n_paths)
	{
		d = solution->paths[i].length - solution->paths[i - 1].length;
		if (ant_count / i <= d)
			break ;
		ant_count -= d * i;
		++i;
	}
	d = ant_count / i;
	ant_count -= d * i;
	solution->n_turns = solution->paths[i - 1].length + d;
	if (solution->n_turns < 0)
		error("too many ants");
	compute_ants_per_path(solution, i);
	return (ant_count);
}

static void		distribute_remainder(int ant_count, t_solution *solution)
{
	int			i;

	if (ant_count == 0)
		solution->n_turns -= 1;
	i = 0;
	while (ant_count--)
	{
		solution->ants_per_path[i] += 1;
		++i;
	}
}

void			distribute_ants(int total_ants, t_solution *solution)
{
	int			remaining_ants;

	remaining_ants = distribute_evenly(total_ants, solution);
	// TODO: if remaining_ants > 0
	distribute_remainder(remaining_ants, solution);
}
