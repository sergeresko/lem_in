/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_more_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:45:48 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 17:14:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// NULL
#include "find_more_paths.h"

static void	adjust_parents(t_room *x)
{
	t_room	*p;
	t_link	*l;
	t_room	*r;

	while ((p = x->parent) != NULL)
	{
		l = p->links->data;
		if (l->weight == 0)
		{
			r = l->dst;
			if (r != x)
				x->parent = r;
			r->parent = p->parent;
		}
		x = x->parent;		// not equivalent to x = p
	}
}

/*
**	reset the `distance` and `parent` fields of all rooms to default values
*/

static void	tidy_up(t_glist *rooms)
{
	t_room	*x;

	while (rooms != NULL)
	{
		x = rooms->data;
		x->distance = INFINITY;
		x->parent = NULL;
		rooms = rooms->next;
	}
}

/*
**	Bhandari's algorithm
*/

t_bool		find_more_paths(t_graph *g)
{
	t_bool	found;

	modify_graph(g->start, g->end);
	found = find_shortest_path(g->start, g->end);
	adjust_parents(g->end);
	restore_graph(g->start, g->end);
	xor_paths(g->start, g->end);
	tidy_up(g->rooms);
	return (found);
}