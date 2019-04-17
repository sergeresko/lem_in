/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:52:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 17:09:23 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// NULL
#include "lem_in.h"

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
		link_push(x->succ, y, -1);
		link_push(y, x, 0);
		if (x->pred == start)
		{
			link_delete(start, x);
			link_push(x, start, -1);
			// break;
		}
		x = x->pred;
	}
}

void		modify_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_room	*x;

	links = end->links;
	while (links != NULL)
	{
		x = links->data;
		if (x->succ == end)
			modify_path(start, x, end);
		links = links->next;
	}
}
