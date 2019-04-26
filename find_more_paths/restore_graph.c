/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:04:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/25 19:49:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// free
#include "datatypes.h"

/*
**	restore the path whose last room before `end` in the modified graph is `y`
**
**	TODO: [Description]
*/

static void	restore_path(t_room *start, t_room *y, t_room *end)
{
	t_room	*x;
	t_room	*z;

	link_delete(end, y);
	while (y != start)
	{
		x = link_pop(y);
		z = link_pop(x);
		x->links = y->links;
		free(y);			// instead of room_destroy
		link_push(x, x->succ, LINK_POSITIVE);
		link_push(x->succ, x, LINK_POSITIVE);
		y = z;
	}
	link_push(start, x, LINK_POSITIVE);
	link_push(x, start, LINK_POSITIVE);
}

/*
**	restore every path that had been described by `pred`/`succ`
*/

void		restore_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(start, l->dst, end);
	}
}
