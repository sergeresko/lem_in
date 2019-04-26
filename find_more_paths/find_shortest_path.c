/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:05 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 14:13:58 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"

void		update_neighbors(t_room *src, t_set *s)
{
	t_glist	*links;
	t_link	*l;
	t_room	*dst;
	int		new_distance;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		dst = l->dst;
		new_distance = src->distance + l->weight;
		if (new_distance < dst->distance)
		{
			dst->distance = new_distance;
			dst->parent = src;
			set_push(s, dst);
		}
		links = links->next;
	}
}

/*
**	modified Dijkstra's algorithm
*/

t_bool		find_shortest_path(t_room *src, t_room *end)
{
	t_set	*s;

	s = set_new();
	src->distance = 0;
	while (src != NULL && src != end)
	{
		update_neighbors(src, s);
		src = set_pop_min(s);		// if s is empty, returns NULL
	}
	set_destroy(&s);
	return (src == end);
}
