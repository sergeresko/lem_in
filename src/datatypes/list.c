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

#include <stdlib.h>
#include "libft.h"
#include "datatypes.h"

void			list_push(t_list **head, void *data)
{
	t_list		*item;

	item = ft_malloc_or_die(sizeof(t_list));
	item->data = data;
	item->next = *head;
	*head = item;
}

/*
**	NOTE: If the function didn't have to return a value, it could be made void
**	and the three lines containing `data` could be removed.
*/

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
