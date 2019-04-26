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

#include <stdlib.h>		// malloc, free
#include "datatypes.h"

/*
**	allocate a new element initialized with `data`
**	TODO: to be removed
*/

t_glist		*glist_new(void *data)
{
	t_glist	*elem;

	elem = malloc(sizeof(t_glist));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void		glist_push(t_glist **head, void *data)
{
	t_glist	*item;

	item = malloc(sizeof(t_glist));
	item->data = data;
	item->next = *head;
	*head = item;
}

//	the return value is never used, so the function may be made void
//	and all lines with `data` removed from its body
void		*glist_pop(t_glist **head)
{
	t_glist	*item;
	void	*data;

	item = *head;
	*head = item->next;
	data = item->data;
	free(item);
	return (data);
}
