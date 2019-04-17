/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:42:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 20:33:27 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

void		link_push(t_room *src, t_room const *dst, int weight)
{
	t_link	*l;

	l = malloc(sizeof(t_link));		// TODO: check memory
	l->dst = dst;
	l->weight = weight;
	glist_push(&src->links, glist_new(l));	// glist_push_new(&src->links, l);
}

t_room		*link_pop(t_room *src)
{
//	t_list	*n;
	t_link	*l;
	t_room	*dst;

	if (src->links == NULL)
		return (NULL);
//	n = src->links->next;
	l = src->links->data;
	dst = l->dst;
	free(l);
//	free(src->links);
//	src->links = n;
	//
	glist_delete(&src->links);
	//
	return (dst);
}

void		link_delete(t_room *src, t_room *dst)
{
	t_list	*links;
	t_link	*l;

	l = src->links->data;
	if (l->dst == dst)
	{
		free(l);
		glist_delete(&src->links);
		return ;
	}
	links = src->links;
	while (links->next != NULL)
	{
		l = links->next->data;
		if (l->dst == dst)
		{
			free(l);
			glist_delete(&links->next);
			return ;
		}
		links = links->next;
	}
}
