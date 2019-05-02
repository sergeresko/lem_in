/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:54:33 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:13:47 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include "error.h"

static void		lem_init(t_lem *lem)
{
	lem->graph.rooms = NULL;
	lem->graph.start = NULL;
	lem->graph.end = NULL;
	lem->input.line_count = 0;
	lem->input.lines = NULL;
	lem->input.last = NULL;
//	lem->input.turn_count = 0;		// not needed (used only in verifier)
}

static void		read_eof(t_lem *lem, t_token *token)
{
	if (token->type != TOKEN_EOF)
		error_at_line(lem, "invalid link (format: name1-name2)");
	if (lem->graph.start == NULL)
		error("start is missing");
	if (lem->graph.end == NULL)
		error("end is missing");
}

void			read_input(t_lem *lem)
{
	t_token		token;

	lem_init(lem);
	get_next_token(lem, &token);
	read_ants(lem, &token);
	read_rooms(lem, &token);
	read_links(lem, &token);
	read_eof(lem, &token);
}
