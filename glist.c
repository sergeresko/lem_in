/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:34:26 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 20:15:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

t_glist		*glist_new(void *data)
{
	t_glist	*elem;

	elem = malloc(sizeof(t_glist));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void		glist_push(t_glist **head, t_glist *elem)
{
	elem->next = *head;
	*head = elem;
}

//	deletes one element assuming it exists
//	If elem is inside a list and p->next = elem, call it like this:
//		glist_delete(&p->next);
void		glist_delete(t_glist **elem)
{
	t_glist	*n;

	n = (*elem)->next;
	free(*elem);
	*elem = n;
}
