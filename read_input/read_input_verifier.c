// <
//
#include <stdlib.h>		// malloc
//
// >
#include "lem_in.h"		// not really needed, since read_input.h includes it
#include "read_input.h"

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

	lem->loc = malloc(lem->total_ants * sizeof(t_room *));	// TODO: check mem
	i = lem->total_ants;
	while (i--)
		lem->loc[i] = lem->graph.start;
}

static void		read_empty_line(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_EOF)
		lem_die("solution is missing");				//
	if (token->type != TOKEN_EMPTY_LINE)
		lem_die_at_line(lem, "invalid link (format: name1-name2)");
	if (lem->graph.start == NULL)
		lem_die("start is missing");
	if (lem->graph.end == NULL)
		lem_die("end is missing");
	lem_init_loc(lem);
	get_next_token(lem, token);
}

static void		read_eof(t_lem *lem, t_token *token)
{
	int		i;

	if (token->type != TOKEN_EOF)
		lem_die_at_line(lem, "invalid turn (example: L1-A L5-toto L12-q)");	//
	i = 0;
	while (i < lem->total_ants)
	{
		if (lem->loc[i] != lem->graph.end)
			lem_die_number("ant ", i + 1, " has not reached the end");
		++i;
	}
}

void			read_input_verifier(t_lem *lem)
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
