/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:52:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 17:31:47 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include <stdio.h>		// printf for debugging
//
//
#include <stdlib.h>		// NULL
#include "lem_in.h"

/*
**	modify the path whose last room before `end` is `x`
**
**	TODO: [Description]
*/

static void	modify_path(t_room *start, t_room *x, t_room *end)
{
	t_room	*y;

	link_delete(end, x);
	while (x != start)
	{
		link_delete(x, x->succ);
		link_delete(x, x->pred);
		y = room_new();				//
		y->links = x->links;
		x->links = NULL;
		link_push(x->succ, y, LINK_NEGATIVE);
		link_push(y, x, LINK_ZERO);
		if (x->pred == start)
		{
			link_delete(start, x);
			link_push(x, start, LINK_NEGATIVE);
			// break;
		}
//	printf("HELLO\n");
		x = x->pred;
	}
}

/*
**	modify every path described by `pred`/`succ`
*/

void		modify_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->dst->succ == end)
			modify_path(start, l->dst, end);
	}
}
