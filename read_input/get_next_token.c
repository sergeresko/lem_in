/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:05:54 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 12:58:01 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		// STDIN_FILENO
#include <stdlib.h>		// exit
#include "libft.h"		// get_next_line, GNL_OK, ...
#include "lem_in.h"		// not really needed, since read_input.h includes it
#include "read_input.h"

static void	save_line(char *str, t_input *input)
{
	t_glist	*item;

	item = glist_new(str);
	if (input->lines == NULL)
		input->lines = item;
	else
		input->tail->next = item;
	input->tail = item;
	input->line_count += 1;
}

/*
**	read and save lines until first non-comment or end of file,
**	construct a respective token
*/

void		get_next_token(t_lem *lem, t_token *token)
{
	int		status;
	char	*str;

	while ((status = get_next_line(STDIN_FILENO, &str)) == GNL_OK)
	{
		save_line(str, lem->input);
		tokenize(str, token);
		if (token->type != TOKEN_COMMENT)
			return ;
	}
	if (status == GNL_EOF)
	{
		token->type = TOKEN_EOF;
		return ;
	}
	if (status == GNL_ERROR)
	{
		// TODO:
		exit(1);	/////////////////////////
	}
}
