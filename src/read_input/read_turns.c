/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_turns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:06:47 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 14:06:52 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read_input.h"
#include "error.h"

/*
**	clear and free the array of moves
*/

static void		clear_token(t_token *token)
{
	int			i;

	i = 0;
	while (i < token->value.turn.len)
	{
		free(token->value.turn.moves[i].dst);
		++i;
	}
	free(token->value.turn.moves);
}

static void		check_label(t_lem const *lem, t_token const *token, int i)
{
	int const	ant = token->value.turn.moves[i].ant;
	int			j;

	if (ant < 1)
		error_at_line(lem, "ant's label non-positive");
	if (ant > lem->total_ants)
		error_at_line(lem, "ant's label exceeds the total amount of ants");
	j = 0;
	while (j < i)
	{
		if (token->value.turn.moves[j].ant == ant)
			error_at_line_nbr(lem, "ant ", ant, " moves more than once");
		++j;
	}
}

/*
**	process the i-th move of the turn by storing the destination room in array
**		`lem->loc` at the index corresponding to the ant's label
**
**	NOTE: The `distance` field is abused to indicate whether a room is free.
**		A free room is marked by INFINITY and an occupied one by 0.
**		The start and end rooms always have INFINITY.
*/

static void		read_move(t_lem *lem, t_token const *token, int i)
{
	int const	ant = token->value.turn.moves[i].ant;
	t_room		*src;
	t_room		*dst;

	check_label(lem, token, i);
	src = lem->loc[ant - 1];
	dst = room_find(lem->graph.rooms, token->value.turn.moves[i].dst);
	if (dst == NULL)
		error_at_line_nbr(lem, "ant ", ant, " moves to a non-existent room");
	if (link_find(src, dst) == NULL)
		error_at_line_nbr(lem, "ant ", ant, " moves to a non-adjacent room");
	if (dst->distance == 0)
		error_at_line_nbr(lem, "ant ", ant, " moves to an occupied room");
	src->distance = INFINITY;
	if (dst != lem->graph.start && dst != lem->graph.end)
		dst->distance = 0;
	lem->loc[ant - 1] = dst;
}

static t_bool	read_turn(t_lem *lem, t_token *token)
{
	int			i;

	if (token->type == TOKEN_TURN)
	{
		i = 0;
		while (i < token->value.turn.len)
		{
			read_move(lem, token, i);
			++i;
		}
		clear_token(token);
		lem->input.turn_count += 1;
	}
	return (token->type == TOKEN_TURN);
}

void		read_turns(t_lem *lem, t_token *token)
{
	while (read_turn(lem, token))
		get_next_token(lem, token);
}
