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

#include <stdlib.h>		// malloc, NULL
#include "lem_in.h"

/*
**	A quite inefficient implementation.
*/

t_set		*set_new(void)
{
	t_set	*s;

	s = malloc(sizeof(t_set));		// check memory
	s->elements = NULL;
	return (s);
}

// Check if x is already in set; if not, add it.
void		set_push(t_set *s, t_room *x)
{
	t_glist	*e;

	e = s->elements;
	while (e != NULL)
	{
		if (e->data == x)
			return ;
		e = e->next;
	}
	glist_push(&s->elements, glist_new(x));
}

// Exclude a room with smallest distance and return it.
// If set is empty, return NULL.
t_room		*set_pop_min(t_set *s)
{
	t_glist	*e;
	t_glist	*e_min;
	int		min;
	t_room	*r;

	// if set is empty
	if (s->elements == NULL)
		return (NULL);
	// otherwise
	e = s->elements;
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

	if (s->elements == e_min)
	{
		glist_delete(&s->elements);
		return (r);
	}
	e = s->elements;
	while (e->next != e_min)
		e = e->next;
	glist_delete(&e->next);
	return (r);
}

void		set_destroy(t_set **s)
{
	t_glist	*e;
	t_glist	*n;

	e = (*s)->elements;
	while (e != NULL)
	{
		n = e->next;
		free(e);
		e = n;
	}
	free(*s);
	*s = NULL;
}
