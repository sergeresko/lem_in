/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:04:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/21 19:21:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// size_t, free
#include "libft.h"		// TODO:
#include "parse.h"

int		ft_atoi_strict(char const *str, int *value)		// t_bool
{
	int		sign;
	int		abs;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	if (*str == '\0')
		return (0);			// FALSE
	n = 0;
	while ('0' <= *str && *str <= '9')
	{
		abs = abs * 10 + (int)(*str - '0');
		if (abs < 0)
			return (0);		// FALSE
		++str;
	}
	if (*str)
		return (0);			// FALSE
	*value = sign * abs;
	return (1);				// TRUE
}

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

void		parse_command(char const *str, t_token *t)
{
	if (ft_strcmp(str, "##start") == 0)
		t->type = TOKEN_COMMAND_START;
	else if (ft_strcmp(str, "##end") == 0)
		t->type = TOKEN_COMMAND_END;
	else
		t->type = TOKEN_COMMENT;
}

// TODO:
void		parse_turn(char const *str, t_token *t)
{
	(void)str;
	t->type = TOKEN_TURN;
}

void		parse_room(char const *str, t_token *t)
{
	char	**words;

	words = ft_strsplit(str, ' ');
	if (words && words[0] && words[1] && words[2] && !words[3]
			&& !ft_strchr(words[0], '-')
			&& ft_atoi_strict(words[1], &t->value.room.x)
			&& ft_atoi_strict(words[2], &t->value.room.y))
	{
		t->type = TOKEN_ROOM;
		t->value.room.name = words[0];
		free(words[1]);
		free(words[2]);
		free(words);
	}
	else
	{
		t->type = TOKEN_ERROR;
		ft_clear_tab(words);		// TODO: replace this function
	}
}

void		parse_link(char const *str, t_token *t)
{
	size_t		i;
	char const	*dst;

	i = 0;
	while (str[i] != '-')
		++i;
	dst = str + i + 1;
	if (i > 0 && *dst && !ft_strchr(dst, '-'))
	{
		t->type = TOKEN_LINK;
		t->value.link.src = ft_strsub(str, 0, i);
		t->value.link.dst = ft_strdup(dst);
	}
	else
		t->type = TOKEN_ERROR;
}

//	NOTE that the number of ants may be zero!

void		parse_ants(char const *str, t_token *t)
{
	int		n;

	if (ft_atoi_strict(str, &n) && n >= 0)
	{
		t->type = TOKEN_ANTS;
		t->value.ants = n;
	}
	else
		t->type = TOKEN_ERROR;
}

t_token		parse(char *str)
{
	t_token	t;

	if (str[0] == '#')
	{
		if (str[1] == '#')
			return (parse_command(str, &t));
		t.type = TOKEN_COMMENT;
		return (t);
	}
	if (str[0] == 'L')
		return (parse_turn(str, &t));
	if (ft_strchr(str, ' '))
		return (parse_room(str, &t));
	if (ft_strchr(str, '-'))
		return (parse_link(str, &t));
	if (*str == '\0')
	{
		t.type = TOKEN_EMPTY_LINE;
		return (t);
	}
	return (parse_ants(str, &t));
}
