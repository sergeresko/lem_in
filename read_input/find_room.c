/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:10:18 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/23 18:11:17 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		// ft_strcmp
#include "datatypes.h"

/*
**	return the room called `name` or NULL if it is not in the list
*/

t_room		*find_room(t_glist const *rooms, char const *room_name)
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
