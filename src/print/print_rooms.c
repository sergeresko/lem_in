/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:55:05 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:23:27 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "datatypes.h"

static void		print_neighbors(t_room const *room)
{
	t_list		*links;
	t_link		*l;

	links = room->links;
	while (links != NULL)
	{
		l = links->data;
		ft_putchar(' ');
		ft_putstr(l->dst->name);
		links = links->next;
	}
}

static void		print_room(t_room const *room)
{
	ft_putstr("#   ");
	ft_putstr(room->name);
	ft_putstr(" - [");
	print_neighbors(room);
	ft_putstr(" ]\n");
}

void			print_rooms(t_graph const *graph)
{
	t_list		*rooms;
	t_room		*room;

	ft_putstr("#\n#   Rooms:\n#\n");
	rooms = graph->rooms;
	while (rooms != NULL)
	{
		room = rooms->data;
		if (room == graph->start)
			ft_putstr("#   ##start\n");
		else if (room == graph->end)
			ft_putstr("#   ##end\n");
		print_room(rooms->data);
		rooms = rooms->next;
	}
	ft_putstr("#\n");
}
