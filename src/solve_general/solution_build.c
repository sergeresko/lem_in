/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:48:50 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/25 19:53:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solve_general.h"

static int		path_length(t_room *origin)
{
	int			len;

	len = 0;
	while (origin != NULL)
	{
		++len;
		origin = origin->succ;		// ->... ? [sic!]
	}
	return (len);
}

static t_path	*init_paths(int n_paths, t_room const *start)
{
	t_path		*paths;
	t_list		*links;
	t_link		*l;
	int			i;

	paths = ft_malloc_or_die(n_paths * sizeof(t_path));
	links = start->links;
	i = 0;
	while (i < n_paths)
	{
		l = links->data;			// r = ((t_room *)links->data)->dst;
		if (l->dst->pred != NULL)		// equivalent to `l->dst->pred == start`
		{								// or `l->dst->succ != NULL`
			paths[i].origin = l->dst;
			paths[i].length = path_length(l->dst);
//			paths[i].n_ants = 0;		//
			++i;
		}
		links = links->next;
	}
	return (paths);
}

/*
**	sort an array of paths by length in non-descending order
*/

static void		sort_paths(int n_paths, t_path *paths)
{
	int			i;
	int			j;
	t_path		tmp;

	i = 0;
	while (i < n_paths - 1)
	{
		j = i + 1;
		while (j < n_paths)
		{
			if (paths[i].length > paths[j].length)
			{
				tmp = paths[i];
				paths[i] = paths[j];
				paths[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

t_solution		*solution_build(int n_ants, t_room const *start, int n_paths)
{
	t_solution	*solution;

	solution = ft_malloc_or_die(sizeof(t_solution));
	solution->n_paths = n_paths;
	solution->paths = init_paths(n_paths, start);
	sort_paths(n_paths, solution->paths);
	solution->ants_per_path = ft_malloc_or_die(n_paths * sizeof(int));
	distribute_ants(n_ants, solution);
	return (solution);
}

