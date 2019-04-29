// verifier, the Very Fire of lem-in

#include <stdlib.h>		// malloc, free
#include "libft.h"
#include "read_input.h"

static int		array_length(char *const *array)
{
	int			len;

	len = 0;
	while (*(array++) != NULL)
		++len;
	return (len);
}

static t_bool	parse_move(char const *str, t_move *move)
{
	size_t		i;
	char const	*dst;
	char		*ant;

	i = 0;
	while (str[i] != '\0' && str[i] != '-')
		++i;
	dst = str + i + 1;
	if (str[0] == 'L' && str[i] == '-' && i > 1 && *dst && !ft_strchr(dst, '-'))
	{
		ant = ft_strsub(str, 1, i - 1);
		if (ft_atoi_strict(ant, &move->ant))
		{
			free(ant);
			move->dst = ft_strdup(dst);
			return (TRUE);
		}
		free(ant);
	}
	return (FALSE); 
}

void			tokenize_turn(char const *line, t_token *token)
{
	char		**words;
	int			len;
	t_move		*moves;
	int			i;

	words = ft_strsplit(line, ' ');
	len = array_length(words);
	moves = malloc(len * sizeof(t_move));	// TODO: ft_malloc_or_die
	i = 0;
	while (i < len && parse_move(words[i], &moves[i]))
		++i;
	ft_clear_tab((void **)words);		// TODO: replace this function
	if (i == len)
	{
		token->type = TOKEN_TURN;
		token->value.turn.moves = moves;
		token->value.turn.len = len;
		// <
		//
//		ft_putstr("\033[32mDebug: OK\033[0m\n");
		//
		// >
	}
	else
	{
		token->type = TOKEN_ERROR;
		while (i--)
			free(moves[i].dst);
		free(moves);
	}
}
