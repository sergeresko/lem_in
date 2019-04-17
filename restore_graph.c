/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:04:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 17:12:55 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// free, NULL
#include "lem_in.h"

static void	restore_path(t_room *start, t_room *y, t_room *t)
{
	t_room	*x;
	t_room	*z;

	link_delete(t, y);
	while (y != start)
	{
		x = link_pop(y);
		z = link_pop(x);
		x->links = y->links;
		free(y);			// instead of room_destroy
		link_push(x, t, 1);		// t == x->succ
		link_push(t, x, 1);		// t == x->succ
		t = x;
		y = z;
	}
	link_push(start, t, 1);		// y == start
	link_push(t, start, 1);		// y == start
}

void		restore_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		if (l->weight == -1)
			restore_path(start, l->dst, end);
		links = links->next;
	}
}
