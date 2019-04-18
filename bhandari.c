/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:45:48 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 16:48:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include <stdio.h>		// printf for debugging
//
//
#include <stdlib.h>		// NULL
#include "lem_in.h"

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

static void	clear_dist_parent(t_glist *rooms)
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

int			bhandari(t_graph *g)	// t_bool
{
	int		res;				// t_bool

	modify_graph(g->start, g->end);
	res = dijkstra(g->start, g->end);
	adjust_parents(g->end);
	restore_graph(g->start, g->end);
	printf("BHANDARI - HELLO\n");		//
	xor_paths(g->start, g->end);
	clear_dist_parent(g->rooms);
	return (res);
}
