/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:05 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 19:50:32 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// NULL
#include "lem_in.h"

// TODO: rename
void		body(t_set *s, t_room *src)
{
	t_list	*links;
	t_link	*l;
	t_room	*dst;
	int		d;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		dst = l->dst;
		d = src->distance + l->weight;
		if (d < dst->distance)
		{
			dst->distance = d;
			dst->parent = src;
			set_add(s, dst);
		}
		links = links->next;
	}
}

int			dijkstra(t_room *src, t_room *end)		// t_bool
{
	t_set	*s;

	src->distance = 0;
	s = set_new();
	while (src != NULL && src != end)
	{
		body();
		src = set_pop_min(s);		// if s is empty, returns NULL
	}
	set_destroy(&s);
	return (end->distance != INFINITY);
}
