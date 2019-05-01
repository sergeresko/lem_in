/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:05:54 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:12:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "lem_in.h"
#include "get_next_token.h"
#include "error.h"

static void		save_line(char *line, t_input *input)
{
	if (input->lines == NULL)
	{
		list_push(&input->lines, line);
		input->last = input->lines;
	}
	else
	{
		list_push(&input->last->next, line);
		input->last = input->last->next;
	}
	input->line_count += 1;
	if (input->line_count < 0)
		error("file too large");
}

void			get_next_token(t_lem *lem, t_token *token)
{
	int			status;
	char		*line;

	while ((status = get_next_line(STDIN_FILENO, &line)) == GNL_OK)
	{
		save_line(line, &lem->input);
		tokenize(line, token);
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
		perror("get_next_line");
		die();
	}
}
