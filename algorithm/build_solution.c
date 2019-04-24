/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:48:50 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:20:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include "libft.h"		// for debugging
//
//
#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

static int	path_length(t_room *origin)
{
	int		len;

	len = 0;
	while (origin != NULL)
	{
		++len;
		origin = origin->succ;		// ->... ?
	}
	return (len);
}

static t_path	*init_paths(int n_paths, t_room *start)
{
	t_path	*paths;
	t_glist *links;
	t_link	*l;
	int		i;

	paths = malloc(n_paths * sizeof(t_path));	// check memory
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

static void	sort_paths(int n_paths, t_path *paths)
{
	int		i;
	int		j;
	t_path	tmp;

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

t_solution	*build_solution(int n_ants, t_room *start, int n_paths)
{
	t_solution	*s;

	s = malloc(sizeof(t_solution));
	s->n_paths = n_paths;
	s->paths = init_paths(n_paths, start);
	sort_paths(n_paths, s->paths);
	s->ants_per_path = malloc(n_ants * sizeof(int));
	distribute_ants(n_ants, s);
	return (s);
}

void	solution_destroy(t_solution *s)
{
	free(s->paths);
	// <
	//
	ft_putstr("##### solution_destroy: s->paths freed\n");
	//
	// >
	free(s->ants_per_path);
	free(s);
}
