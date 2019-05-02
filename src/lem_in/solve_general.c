/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:21:34 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/27 17:37:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include "print.h"
#include "solve_general.h"
#include "error.h"

static int		count_links(t_room const *src)
{
	int			count;
	t_list		*links;

	count = 0;
	links = src->links;
	while (links != NULL)
	{
		++count;
		links = links->next;
	}
	return (count);
}

/*
**	return the smallest of the three numbers: total number of ants, number
**	of outlets from the start room, and number of inlets to the end room
*/

static int		compute_max_paths(t_lem const *lem)
{
	int			max_paths;
	int			n;

	max_paths = lem->total_ants;
	if ((n = count_links(lem->graph.start)) < max_paths)
		max_paths = n;
	if ((n = count_links(lem->graph.end)) < max_paths)
		max_paths = n;
	return (max_paths);
}

static void		print_paths(t_solution const *solution, t_room const *start)
{
	int		i;

	print_total("paths", solution->n_paths);
	i = 0;
	while (i < solution->n_paths)
	{
		print_path(solution->ants_per_path[i], solution->paths[i].length,
				start, solution->paths[i].origin);
		++i;
	}
	ft_putstr("#\n");
}

static void		print_solution(t_solution *best_solution, t_lem const *lem)
{
	if (lem->options.paths)
		print_paths(best_solution, lem->graph.start);
	if (lem->options.turns)
		print_total("turns", best_solution->n_turns);
	if (lem->options.moves)
		print_moves(best_solution, lem->total_ants);
}

void			solve_general(t_lem *lem)
{
	int const	max_paths = compute_max_paths(lem);
	int			path_count;
	t_solution	*best_solution;

	path_count = 0;
	best_solution = NULL;
	while (path_count < max_paths && find_more_paths(&lem->graph))
	{
		++path_count;
		solution_improve(&best_solution,
				lem->total_ants, lem->graph.start, path_count);
	}
	if (path_count == 0)
		error("no solution (end is not reachable)");
	print_solution(best_solution, lem);
	solution_destroy(best_solution);
}
