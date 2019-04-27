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

t_set		*set_new(void)
{
	t_set	*set;

	set = malloc(sizeof(t_set));		// check memory
	set->elements = NULL;
	return (set);
}

void		set_push(t_set *set, t_room *room)
{
	t_list	*e;

	e = set->elements;
	while (e != NULL)
	{
		if (e->data == room)
			return ;
		e = e->next;
	}
	list_push(&set->elements, room);
}

t_room		*set_pop_min(t_set *set)
{
	t_list	*e;
	t_list	*e_min;
	int		min;
	t_room	*r;

	// if set is empty
	if (set->elements == NULL)
		return (NULL);
	// otherwise
	// TODO: refactor, see link_delete
	e = set->elements;
	r = e->data;
	e_min = e;
	min = r->distance;
	while (e != NULL)
	{
		r = e->data;
		if (r->distance < min)
		{
			e_min = e;
			min = r->distance;
		}
		e = e->next;
	}
	r = e_min->data;

	if (set->elements == e_min)
	{
		(void)list_pop(&set->elements);
		return (r);
	}
	e = set->elements;
	while (e->next != e_min)
		e = e->next;
	(void)list_pop(&e->next);
	return (r);
	// TODO: new version
	/*
	t_list	**addr;
	t_list	**addr_min;
	int		min_distance

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
		*addr = (*addr)->next;
	}
	return (list_pop(addr_min));
	*/
}

// TODO: reimplement with list_pop
// Don't assign NULL, pass just t_set *set.
void		set_destroy(t_set **set)
{
	t_list	*e;
	t_list	*n;

	e = (*set)->elements;
	while (e != NULL)
	{
		n = e->next;
		free(e);
		e = n;
	}
	free(*set);
	*set = NULL;
}
// TODO: new version
/*
void		set_destroy(t_set *set)
{
	while (set->elements != NULL)
		(void)list_pop(&set->elements);
	free(set);
}
*/