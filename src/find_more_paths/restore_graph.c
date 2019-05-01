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

#include <stdlib.h>
#include "datatypes.h"

/*
**	restore the path whose last room before `end` in the modified graph is `out`
**
**	Pairs of rooms that result from splitting are coalesced, and negative
**	and zero-weight unidirectional links are replaced with original positive
**	bidirectional ones.
**
**	What distinguishes the current state of the graph from the original one
**	(before modification) is that `parent` fields now describe the new path.
*/

static void		restore_path(t_room *start, t_room *out, t_room *end)
{
	t_room		*in;
	t_room		*pred_out;

	link_delete(end, out);
	while (out != start)
	{
		in = link_pop(out);
		pred_out = link_pop(in);
		in->links = out->links;
		free(out);
		link_push(in, in->succ, LINK_POSITIVE);
		link_push(in->succ, in, LINK_POSITIVE);
		out = pred_out;
	}
	link_push(start, in, LINK_POSITIVE);
	link_push(in, start, LINK_POSITIVE);
}

/*
**	restore every path that had been described by `pred`/`succ`
*/

void			restore_graph(t_room *start, t_room *end)
{
	t_list		*links;
	t_link		*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(start, l->dst, end);
	}
}
