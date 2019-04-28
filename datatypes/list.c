/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:34:26 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 20:15:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc, free
#include "datatypes.h"

void			list_push(t_list **head, void *data)
{
	t_list		*item;

	item = malloc(sizeof(t_list));
	item->data = data;
	item->next = *head;
	*head = item;
}

//	the return value is never used, so the function may be made void
//	and all lines with `data` removed from its body
void			*list_pop(t_list **head)
{
	t_list		*item;
	void		*data;

	item = *head;
	*head = item->next;
	data = item->data;
	free(item);
	return (data);
}
