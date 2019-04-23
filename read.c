#include <stdlib.h>		// NULL
#include "lem_in.h"
#include "parse.h"

void		read_eof(t_lem *lem, t_token *token)
{
	if (token->type != TOKEN_EOF)
		lem_die(lem, "invalid link (format: name1-name2)");
	if (lem->graph->start == NULL)
		lem_die_eof("start room is missing");	// without line number
	if (lem->graph->end == NULL)
		lem_die_eof("end room is missing");	// without line number
}

void		read_input(t_lem *lem)
{
	t_token	token;

	get_next_token(lem, &token);
	read_ants(lem, &token);
	read_rooms(lem, &token);
	read_links(lem, &token);
	read_eof(lem, &token);
}