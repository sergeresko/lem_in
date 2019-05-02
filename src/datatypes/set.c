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
**	list: both `set_push` and `set_pop_min` take O(N) time where N is the
**	current cardinality.
*/

#include <stdlib.h>
#include "libft.h"
#include "datatypes.h"

t_set			*set_new(void)
{
	t_set		*set;

	set = ft_malloc_or_die(sizeof(t_set));
	set->elements = NULL;
	return (set);
}

void			set_push(t_set *set, t_room *room)
{
	t_list		*element;

	element = set->elements;
	while (element != NULL)
	{
		if (element->data == room)
			return ;
		element = element->next;
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
