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

/*
**	to the list of links from room `src` prepend a new link to room `dst`
**	of specified weight
*/

void		link_push(t_room *src, t_room *dst, int weight)
{
	t_link	*l;

	l = malloc(sizeof(t_link));		// TODO: check memory
	l->dst = dst;
	l->weight = weight;
	glist_push(&src->links, glist_new(l));	// glist_push_new(&src->links, l);
}

/*
**	remove the first link from room `src` and return that link's destination
*/

t_room		*link_pop(t_room *src)
{
	t_link	*l;
	t_room	*dst;

	if (src->links == NULL)
		return (NULL);
	l = src->links->data;
	dst = l->dst;
	free(l);
	glist_delete(&src->links);
	return (dst);
}

/*
**	remove the link from room `src` to room `dst`
*/

void		link_delete(t_room *src, t_room *dst)
{
	t_glist	*links;
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
