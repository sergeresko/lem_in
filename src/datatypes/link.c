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

#include <stdlib.h>
#include "libft.h"
#include "datatypes.h"

void			link_push(t_room *src, t_room *dst, int weight)
{
	t_link		*l;

	l = ft_malloc_or_die(sizeof(t_link));
	l->dst = dst;
	l->weight = weight;
	list_push(&src->links, l);
}

/*
**	CAUTION: The behavior is undefined if the room has no links.
*/

t_room			*link_pop(t_room *src)
{
	t_room		*dst;

	dst = ((t_link *)src->links->data)->dst;
	free(list_pop(&src->links));
	return (dst);
}

/*
**	CAUTION: The behavior is undefined if the first room does not have a link
**	to the second one.
*/

void			link_delete(t_room *src, t_room *dst)
{
	t_list		**addr;

	addr = &src->links;
	while (((t_link *)(*addr)->data)->dst != dst)
		addr = &(*addr)->next;
	free(list_pop(addr));
}

t_link			*link_find(t_room const *src, t_room const *dst)
{
	t_list		*links;

	links = src->links;
	while (links != NULL)
	{
		if (((t_link *)links->data)->dst == dst)
			return (links->data);
		links = links->next;
	}
	return (NULL);
}
