// TODO: stub

#include <stdlib.h>			// free
#include "read_input.h"

static t_bool	read_turn(t_lem *lem, t_token *token)
{
	int			i;
	//
	(void)lem;	//
	//
	if (token->type == TOKEN_TURN)
	{
		// TODO: stub
		i = 0;
		while (i < token->value.turn.len)
		{
			free(token->value.turn.moves[i].dst);
			++i;
		}
		free(token->value.turn.moves);
	}
	return (token->type == TOKEN_TURN);
}

void		read_turns(t_lem *lem, t_token *token)
{
	// TODO: stub
	while (read_turn(lem, token))
		get_next_token(lem, token);
}
