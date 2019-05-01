/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:09:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 14:59:45 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// free
#include "libft.h"		// ft_strcmp
#include "read_input.h"
#include "error.h"

static void		add_link(t_lem *lem, t_token *token)
{
	t_room		*src;
	t_room		*dst;

	if ((src = room_find(lem->graph.rooms, token->value.link.src)) == NULL)
		error_at_line(lem, "left-hand room does not exist");
	if ((dst = room_find(lem->graph.rooms, token->value.link.dst)) == NULL)
		error_at_line(lem, "right-hand room does not exist");
	if (link_find(src, dst) != NULL)
		error_at_line(lem, "rooms already linked");
	link_push(src, dst, LINK_POSITIVE);
	link_push(dst, src, LINK_POSITIVE);
	free(token->value.link.src);
	free(token->value.link.dst);
}

static t_bool	read_link(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_LINK)
	{
		if (ft_strcmp(token->value.link.src, token->value.link.dst) == 0)
			error_at_line(lem, "cannot link a room to itself");
		add_link(lem, token);
	}
	return (token->type == TOKEN_LINK);
}

void			read_links(t_lem *lem, t_token *token)
{
	if (token->type != TOKEN_LINK && token->type != TOKEN_EOF)
		error_at_line(lem, "invalid room or link");
	while (read_link(lem, token))
		get_next_token(lem, token);
}
