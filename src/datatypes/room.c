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

#include "libft.h"
#include "datatypes.h"

/*
**	CAUTION: Fields `name`, `x`, `y` and `best_succ` are left uninitialized.
*/

t_room			*room_new(void)
{
	t_room		*room;

	room = ft_malloc_or_die(sizeof(t_room));
//	room->name = NULL;
//	room->x = 0;
//	room->y = 0;
	room->links = NULL;
	room->distance = INFINITY;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
//	room->best_succ = NULL;
	return (room);
}

t_room			*room_find(t_list const *rooms, char const *room_name)
{
	t_room		*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		if (ft_strcmp(room->name, room_name) == 0)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}
