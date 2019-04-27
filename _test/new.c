/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:21:34 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/27 15:47:42 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// system
#include "lem_in.h"

// ----------------------------------------------------------------------------

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
**	of outlets from the start room, and number of inlets to the end room.
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

//	solve_instant
//	solve_trivial
//	solve_general

static void		print_solution_general(t_solution *best_solution, t_lem *lem)
{
	if (lem->options.paths)
		print_paths(best_solution, lem.graph.start);
	if (lem->options.total)
		print_total(best_solution);
	if (lem->options.moves)
		print_moves(best_solution, lem.total_ants);		// should first print an empty line
}

void			solution_save(t_solution const *solution)
{
	int		i;
	t_room	*room;

	i = 0;
	while (i < solution->n_paths)
	{
		room = solution->paths[i]->origin;
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
		solution_destroy(*best_solution);	// if the argument is NULL, do nothing
		*best_solution = solution;
	}
}

void			solve_general()
{
	int			max_paths;		// const
	int			path_count;
//	t_solution	*solution;
	t_solution	*best_solution;

	max_paths = compute_max_paths(total_ants, graph);
	path_count = 0;
	best_solution = NULL;
	while (path_count < max_paths && find_more_paths(graph))
	{
		++path_count;
		solution_improve(&best_solution, total_ants, graph->start, path_count);
		/*
		solution = solution_build(total_ants, graph->start, path_count);
		if (best_solution == NULL || solution->n_turns < best_solution->n_turns)
		{
			solution_save(...);
			solution_destroy(best_solution);	// if the argument is NULL, do nothing
			best_solution = solution;
		}
		*/
	}
	if (path_count == 0)	// `find_more_paths` failed upon the first call
		lem_die("end is not reachable");
	print_solution_general(best_solution, lem);		// why lem? because of options
	solution_destroy(best_solution);
}

// TODO: decide the order of output and location of the empty line

// ----------------------------------------------------------------------------

// These static functions are not actually needed as they can be inlined.

static void		print_paths_instant(void)
{
	ft_putstr("#\n#   Paths:\n#\n");
	// TODO: number of paths: 0
	ft_putstr("#\n");
}

static void		print_moves_instant(void)
{
	ft_putstr("\n");	// TODO: ?
}

static void		print_total_instant(void)
{
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(0);
	ft_putstr("\n#\n");
}

// if there are zero ants
void			solve_instant(t_options const *opt)
{
	// TODO: reorder
	if (opt->paths)
		print_paths_instant();
	if (opt->moves)
		print_moves_instant();
	if (opt->total)
		print_total_instant();
}

// ----------------------------------------------------------------------------

static void		print_paths_trivial(int total_ants, t_room const *start, t_room const *end)
{
	ft_putstr("#\n#   Paths:\n#\n");
	// TODO: number of paths: 1
	ft_putstr("#   ");
	ft_putnbr(total_ants);
	ft_putstr(" ant");
	if (n_ants != 1)
		ft_putchar('s');
	ft_putstr(" to path [ ");
	ft_putstr(start->name);
	ft_putchar(' ');
	ft_putstr(end->name);
	ft_putstr(" ]\n");
	ft_putstr("#\n");
}

static void		print_moves_trivial(int total_ants, t_room const *end)
{
	int			i;
	t_bool		first;

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

static void		print_total_trivial(void)
{
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(1);
	ft_putstr("\n#\n");
}

void			solve_trivial(t_lem const *lem)
{
	// TODO: reorder, empty line
	if (lem->options.paths)
		print_paths_trivial(lem->total_ants, lem->graph.start, lem->graph.end);
	if (lem->options.moves)
		print_moves_trivial(lem->total_ants, lem->graph->end);
	if (lem->options.total)
		print_total_trivial();
}

// ----------------------------------------------------------------------------

int			main(int argc, char **argv)
{
	t_lem	lem;

	// process options
	read_options(argc, argv, &lem.options);
	// TODO: help
	/*
	if (lem.options.help)
	{
		print_help();
		return (0);
	}
	*/
	// process input
	read_input(&lem);
	if (lem.options.input)
		print_input(&lem.input);
	if (lem.options.rooms)
		print_rooms(&lem.graph);
	// solve
	if (lem.total_ants == 0)
		solve_instant(&lem);
	else if (find_link(lem.graph.start, lem.graph.end) != NULL)
		solve_trivial(&lem);
	else
		solve_general();		//

	system("leaks lem-in");

	return (0);
}
