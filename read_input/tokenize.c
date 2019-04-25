/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:04:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 12:57:14 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// size_t, free
#include "libft.h"
#include "read_input.h"

/*
void	token_destroy(t_token *t)
{
}
*/

/*
int		ft_strprefix(char const *str, char const *prefix)
{
	char	c;

	while ((c = *(prefix++)))
	{
		if (*(str++) != c)
			return (1);
	}
	return (0);
}
*/

static void		tokenize_command_or_comment(char const *str, t_token *token)
{
	if (ft_strcmp(str, "##start") == 0)
		token->type = TOKEN_CMD_START;
	else if (ft_strcmp(str, "##end") == 0)
		token->type = TOKEN_CMD_END;
	else
		token->type = TOKEN_COMMENT;
}

// TODO: to separate file
void		tokenize_turn(char const *str, t_token *token)
{
	(void)str;
	token->type = TOKEN_TURN;
}

static void		tokenize_room(char const *str, t_token *token)
{
	char		**words;

	words = ft_strsplit(str, ' ');
	if (words && words[0] && words[1] && words[2] && !words[3]
			&& !ft_strchr(words[0], '-')
			&& ft_atoi_strict(words[1], &token->value.room.x)
			&& ft_atoi_strict(words[2], &token->value.room.y))
	{
		token->type = TOKEN_ROOM;
		token->value.room.name = words[0];
		free(words[1]);
		free(words[2]);
		free(words);
	}
	else
	{
		token->type = TOKEN_ERROR;
		ft_clear_tab((void **)words);		// TODO: replace this function
	}
}

static void		tokenize_link(char const *str, t_token *token)
{
	size_t		i;
	char const	*dst;

	i = 0;
	while (str[i] != '-')
		++i;
	dst = str + i + 1;
	if (i > 0 && *dst && !ft_strchr(dst, '-'))
	{
		token->type = TOKEN_LINK;
		token->value.link.src = ft_strsub(str, 0, i);
		token->value.link.dst = ft_strdup(dst);
	}
	else
		token->type = TOKEN_ERROR;
}

//	NOTE that the number of ants may be zero!

static void		tokenize_ants(char const *str, t_token *token)
{
	int			number;

	if (ft_atoi_strict(str, &number) && number >= 0)
	{
		token->type = TOKEN_ANTS;
		token->value.ants = number;
	}
	else
		token->type = TOKEN_ERROR;
}

//	the order matters

void		tokenize(char const *str, t_token *token)
{
	if (str[0] == '#')
		tokenize_command_or_comment(str, token);
	else if (str[0] == 'L')
		tokenize_turn(str, token);
	else if (ft_strchr(str, ' '))
		tokenize_room(str, token);
	else if (ft_strchr(str, '-'))
		tokenize_link(str, token);
	else if (str[0] == '\0')
		token->type = TOKEN_EMPTY_LINE;
	else
		tokenize_ants(str, token);
}
