/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:42:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 20:13:55 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free
#include "datatypes.h"
#include "lem_in.h"		// lem_die_from_bug

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
	glist_push(&src->links, l);
}

/*
**	remove the first link from room `src` and return that link's destination
*/

t_room		*link_pop(t_room *src)
{
	t_link	*l;
	t_room	*dst;

	if (src->links == NULL)
	{
		lem_die_from_bug("popping an empty list");
		return (NULL);
	}
	l = src->links->data;
	dst = l->dst;
	free(l);
	(void)glist_pop(&src->links);
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
		(void)glist_pop(&src->links);
		return ;
	}
	links = src->links;
	while (links->next != NULL)
	{
		l = links->next->data;
		if (l->dst == dst)
		{
			free(l);
			(void)glist_pop(&links->next);
			return ;
		}
		links = links->next;
	}
	lem_die_from_bug("no link to delete");
}

/*
**	return the link from `src` to `dst` if it exists or NULL otherwise
*/

t_link		*link_find(t_room *src, t_room *dst)
{
	t_glist	*links;
	t_link	*l;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		if (l->dst == dst)
			return (l);
		links = links->next;
	}
	return (NULL);
}
