/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:36:08 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 16:39:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "libft.h"
#include "datatypes.h"

t_room		*room_new(void)
{
	t_room	*room;

	room = malloc(sizeof(t_room));		// check memory
	room->name = NULL;
//	room->x = 0;
//	room->y = 0;
	room->links = NULL;
	room->distance = INFINITY;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	return (room);
}

/*
**	return the room called `name` or NULL if it is not in the list
*/

t_room		*room_find(t_glist const *rooms, char const *room_name)
{
	t_room	*r;

	while (rooms != NULL)
	{
		r = rooms->data;
		if (ft_strcmp(r->name, room_name) == 0)
			return (r);
		rooms = rooms->next;
	}
	return (NULL);
}