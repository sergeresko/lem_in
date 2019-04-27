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

#include "libft.h"		// for printing
#include "lem_in.h"

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

static int		compute_max_paths(int total_ants, t_graph const *graph)
{
	int			max_paths;
	int			n;

	max_paths = total_ants;
	if ((n = count_links(graph->start)) < max_paths)
		max_paths = n;
	if ((n = count_links(graph->end)) < max_paths)
		max_paths = n;
	return (max_paths);
}

static void		print_solution(t_solution *best_solution, t_lem const *lem)
{
	// TODO: reorder, empty line
	if (lem->options.paths)
		print_paths(best_solution, lem->graph.start);
	if (lem->options.total)
		print_total(best_solution);
	if (lem->options.moves)
		print_moves(best_solution, lem->total_ants);		// should first print an empty line
}

void			solution_save(t_solution const *solution)
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

static void		solution_improve(t_solution **best_solution, int total_ants,
		t_room *start, int path_count)
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

void			solve_general(t_lem *lem)
{
	int			max_paths;		// const
	int			path_count;
	t_solution	*best_solution;

	max_paths = compute_max_paths(lem->total_ants, &lem->graph);
	path_count = 0;
	best_solution = NULL;
	while (path_count < max_paths && find_more_paths(&lem->graph))
	{
		++path_count;
		solution_improve(&best_solution, lem->total_ants, lem->graph.start, path_count);
	}
	if (path_count == 0)	// `find_more_paths` failed upon the first call
		lem_die("end is not reachable");
	print_solution(best_solution, lem);		// why lem? because of options
	solution_destroy(best_solution);
}

// TODO: decide the order of output and location of the empty line
