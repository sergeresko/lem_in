/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:07:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 14:57:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	
#include "libft.h"
#include "get_next_token.h"

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
	moves = ft_malloc_or_die(len * sizeof(t_move));
	i = 0;
	while (i < len && parse_move(words[i], &moves[i]))
		++i;
	ft_strsplit_clear(words);
	if (i == len)
	{
		token->type = TOKEN_TURN;
		token->value.turn.moves = moves;
		token->value.turn.len = len;
	}
	else
	{
		token->type = TOKEN_ERROR;
		while (i--)
			free(moves[i].dst);
		free(moves);
	}
}
