/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:05:55 by syeresko          #+#    #+#             */
/*   Updated: 2019/05/07 15:54:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	lem->input.turn_count = 0;		// added
}

static void		lem_init_loc(t_lem *lem)
{
	int			i;

	lem->loc = ft_malloc_or_die(lem->total_ants * sizeof(t_room *));
	i = lem->total_ants;
	while (i--)
		lem->loc[i] = lem->graph.start;
}

static void		read_empty_line(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_EOF)
		error("solution is missing");
	if (token->type != TOKEN_EMPTY_LINE)
		error_at_line(lem, "invalid link (format: name1-name2)");
	if (lem->graph.start == NULL)
		error("start is missing");
	if (lem->graph.end == NULL)
		error("end is missing");
	lem_init_loc(lem);
	get_next_token(lem, token);
}

static void		read_eof(t_lem *lem, t_token *token)
{
	int			i;

	if (token->type != TOKEN_EOF)
		error_at_line(lem,
				"invalid turn (example: L1-lorem L5-ipsum L42-Toto)");
	i = 0;
	while (i < lem->total_ants)
	{
		if (lem->loc[i] != lem->graph.end)
			error_nbr("ant ", i + 1, " has not reached the end");
		++i;
	}
}

void			read_input(t_lem *lem)
{
	t_token		token;

	lem_init(lem);
	get_next_token(lem, &token);
	read_ants(lem, &token);
	read_rooms(lem, &token);
	read_links(lem, &token);
	read_empty_line(lem, &token);
	read_turns(lem, &token);
	read_eof(lem, &token);
}
