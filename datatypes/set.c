/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:22:30 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 13:22:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This is an inefficient implementation of a mutable set as a singly-linked
**	list: both `set_push` and `set_pop_min` take O(n) time where n is the
**	current cardinality.
*/

#include <stdlib.h>		// malloc, free
#include "lem_in.h"

t_set			*set_new(void)
{
	t_set		*set;

	set = malloc(sizeof(t_set));		// check memory
	set->elements = NULL;
	return (set);
}

void			set_push(t_set *set, t_room *room)
{
	t_list		*e;

	e = set->elements;
	while (e != NULL)
	{
		if (e->data == room)
			return ;
		e = e->next;
	}
	list_push(&set->elements, room);
}

t_room			*set_pop_min(t_set *set)
{
	t_list		**addr;
	t_list		**addr_min;
	int			min_distance;

	if (set->elements == NULL)
		return (NULL);
	addr = &set->elements;
	addr_min = addr;
	min_distance = ((t_room *)(*addr)->data)->distance;
	while (*addr != NULL)
	{
		if (((t_room *)(*addr)->data)->distance < min_distance)
		{
			addr_min = addr;
			min_distance = ((t_room *)(*addr)->data)->distance;
		}
		addr = &(*addr)->next;
	}
	return (list_pop(addr_min));
}

void			set_destroy(t_set *set)
{
	while (set->elements != NULL)
		(void)list_pop(&set->elements);
	free(set);
}
