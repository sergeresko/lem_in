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
//#include "lem_in.h"		// lem_die_from_bug

void		link_push(t_room *src, t_room *dst, int weight)
{
	t_link	*l;

	l = malloc(sizeof(t_link));		// TODO: check memory
	l->dst = dst;
	l->weight = weight;
	list_push(&src->links, l);
}

t_room		*link_pop(t_room *src)
{
	t_link	*l;
	t_room	*dst;

//	if (src->links == NULL)
//	{
//		lem_die_from_bug("popping an empty list");
//		return (NULL);
//	}
	l = src->links->data;
	dst = l->dst;
	free(l);
	(void)list_pop(&src->links);
	return (dst);
}

void		link_delete(t_room *src, t_room *dst)
{
	/*
	t_list	*links;
	t_link	*l;

	l = src->links->data;
	if (l->dst == dst)
	{
		free(l);
		(void)list_pop(&src->links);
		return ;
	}
	links = src->links;
	while (links->next != NULL)
	{
		l = links->next->data;
		if (l->dst == dst)
		{
			free(l);
			(void)list_pop(&links->next);
			return ;
		}
		links = links->next;
	}
	lem_die_from_bug("no link to delete");
	*/
	t_list	**addr;
	t_link	*l;

	addr = &src->links;
	l = (*addr)->data;
	while (l->dst != dst)
	{
		addr = &(*addr)->next;
		l = (*addr)->data;
	}
	free(l);				// equivalent to
	(void)list_pop(addr);	// free(list_pop(addr));
}

t_link		*link_find(t_room *src, t_room *dst)
{
	t_list	*links;
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
