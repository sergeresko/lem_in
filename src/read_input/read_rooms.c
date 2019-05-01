/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:11:24 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:01:15 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include "error.h"

static void		add_room(t_lem *lem, t_token const *token)
{
	t_room		*room;

	if (room_find(lem->graph.rooms, token->value.room.name) != NULL)
		error_at_line(lem, "already has a room with this name");
	room = room_new();
	room->name = token->value.room.name;
	room->x = token->value.room.x;
	room->y = token->value.room.y;
	list_push(&lem->graph.rooms, room);
}

static void		read_start_or_end_room(t_lem *lem, t_token *token)
{
	t_bool		is_start;

	is_start = (token->type == TOKEN_CMD_START);
	if (is_start && lem->graph.start != NULL)
		error_at_line(lem, "already has a start");
	if (!is_start && lem->graph.end != NULL)
		error_at_line(lem, "already has an end");
	get_next_token(lem, token);
	if (token->type == TOKEN_EOF)
		error("unexpected end of file (room is missing)");
	if (token->type != TOKEN_ROOM)
		error_at_line(lem, "invalid room (format: name coord_x coord_y)");
	add_room(lem, token);
	if (is_start)
		lem->graph.start = lem->graph.rooms->data;
	else
		lem->graph.end = lem->graph.rooms->data;
}

static t_bool	read_room(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_ROOM)
		add_room(lem, token);
	else if (token->type == TOKEN_CMD_START || token->type == TOKEN_CMD_END)
		read_start_or_end_room(lem, token);
	return (token->type == TOKEN_ROOM);
}

void			read_rooms(t_lem *lem, t_token *token)
{
	while (read_room(lem, token))
		get_next_token(lem, token);
}
