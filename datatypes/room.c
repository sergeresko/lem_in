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

// {
#ifdef DEBUG
# include "libft.h"		// for debugging
#endif
// }
#include <stdlib.h>		// malloc
#include "libft.h"
#include "datatypes.h"
// {
#ifdef DEBUG
# define DEBUG_PTR(ptr) (((unsigned long long)(ptr) & 0xfffff0) >> 4)
#endif
// }

t_room		*room_new(void)
{
	t_room	*room;

	room = malloc(sizeof(t_room));		// check memory
// {
#ifdef DEBUG
	ft_printf(PF_YELLOW"[malloc %05x (room)]"PF_RESET, DEBUG_PTR(room));	//
#endif
// }
	room->name = NULL;	//
//	room->x = 0;
//	room->y = 0;
	room->links = NULL;
	room->distance = INFINITY;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	return (room);
}

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