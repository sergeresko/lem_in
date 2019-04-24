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

#include <stdlib.h>		// NULL
#include "lem_in.h"		// not really needed, since read_input.h includes it
#include "read_input.h"

static void	add_room(t_lem *lem, t_token *token)
{
	t_room	*room;

	if (find_room(lem->graph.rooms, token->value.room.name) != NULL)
		lem_die_at_line(lem, "already has a room with this name");
	room = room_new();
	room->name = token->value.room.name;
	room->x = token->value.room.x;
	room->y = token->value.room.y;
	glist_push(&lem->graph.rooms, glist_new(room));
}

static void	read_start_or_end_room(t_lem *lem, t_token *token)
{
	int		is_start;		// t_bool

	is_start = (token->type == TOKEN_CMD_START);
	if (is_start && lem->graph.start != NULL)
		lem_die_at_line(lem, "already has a start");
	if (!is_start && lem->graph.end != NULL)
		lem_die_at_line(lem, "already has an end");
	get_next_token(lem, token);
	if (token->type == TOKEN_EOF)
		lem_die("unexpected end of file (room is missing)");
	if (token->type != TOKEN_ROOM)
		lem_die_at_line(lem, "invalid room (format: name coord_x coord_y)");
	add_room(lem, token);
	if (is_start)
		lem->graph.start = lem->graph.rooms->data;
	else
		lem->graph.end = lem->graph.rooms->data;
}

/*	TODO: obsolete description
**	If no error occurred and the function returned FALSE, the final value
**	of `token->type` is one of the following:
**	TOKEN_TURN, TOKEN_LINK, TOKEN_ANTS, TOKEN_EMPTY_LINE, TOKEN_ERROR, TOKEN_EOF.
*/

static int	read_room(t_lem *lem, t_token *token)		// t_bool
{
	if (token->type == TOKEN_ROOM)
		add_room(lem, token);
	else if (token->type == TOKEN_CMD_START || token->type == TOKEN_CMD_END)
		read_start_or_end_room(lem, token);
	return (token->type == TOKEN_ROOM);
}

void		read_rooms(t_lem *lem, t_token *token)
{
//	if (token->type == TOKEN_EOF)
//		lem_die_eof(lem);
//	if (token->type != TOKEN_ROOM)
//		lem_die(lem, "invalid room (format: name coord_x coord_y)");
	while (read_room(lem, token))
		get_next_token(lem, token);
}
