/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_improve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:13:00 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:14:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_general.h"

/*
**	copy the values of `succ` fields to `best_succ` fields
*/

static void		solution_save(t_solution const *solution)
{
	int			i;
	t_room		*room;

	i = 0;
	while (i < solution->n_paths)
	{
		room = solution->paths[i].origin;
		while (room->succ != NULL)
		{
			room->best_succ = room->succ;
			room = room->succ;
		}
		++i;
	}
}

/*
**	build a new solution based on `succ` fields and, if it has less turns than
**	the current best solution, save it and let it be the best one
*/

void			solution_improve(t_solution **best_solution,
						int total_ants, t_room *start, int path_count)
{
	t_solution	*solution;

	solution = solution_build(total_ants, start, path_count);
	if (*best_solution == NULL
			|| solution->n_turns < (*best_solution)->n_turns)
	{
		solution_save(solution);
		if (*best_solution != NULL)
			solution_destroy(*best_solution);
		*best_solution = solution;
	}
	else
		solution_destroy(solution);
}
