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
	// TODO: ...
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
	get_next_token(lem, token);
}

static void		read_eof(t_lem *lem, t_token *token)
{
	if (token->type != TOKEN_EOF)
		lem_die_at_line(lem, "invalid turn (example: L1-A L5-toto L12-q)");	//
	// TODO:
	// if (...) ...
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
