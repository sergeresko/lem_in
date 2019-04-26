/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:52:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/25 19:44:56 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"

/*
**	modify the path whose last room before `end` is `in`
**
**	TODO: [Description]
*/

static void	modify_path(t_room *start, t_room *in, t_room *end)
{
	t_room	*out;

	link_delete(end, in);
	while (in != start)
	{
		link_delete(in, in->succ);
		link_delete(in, in->pred);
		out = room_new();
		out->links = in->links;
		in->links = NULL;
		link_push(in->succ, out, LINK_NEGATIVE);
		link_push(out, in, LINK_ZERO);
		if (in->pred == start)
		{
			link_delete(start, in);
			link_push(in, start, LINK_NEGATIVE);
			// break;
		}
		in = in->pred;
	}
}

/*
**	modify every path described by `pred`/`succ`
*/

void		modify_graph(t_room *start, t_room *end)
{
	t_list	*links;
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
