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

#include <stdlib.h>		// NULL
#include "libft.h"		// ft_strcmp
#include "lem_in.h"		// not really needed, since read_input.h includes it
#include "read_input.h"

//	TODO: make sure that ft_strcmp(src_name, dst_name) != 0

void			add_link(t_lem *lem, t_token *token)
//void		add_link(char const *src_name, char const *dst_name)
{
	t_room		*src;
	t_room		*dst;

	if ((src = find_room(lem->graph.rooms, token->value.link.src)) == NULL)
		lem_die_at_line(lem, "has no room called `src`");		// TODO: change message
	if ((dst = find_room(lem->graph.rooms, token->value.link.dst)) == NULL)
		lem_die_at_line(lem, "has no room called `dst`");		// TODO: change message
	if (link_find(src, dst) != NULL)
		lem_die_at_line(lem, "already has a link between these rooms");
	link_push(src, dst, LINK_POSITIVE);
	link_push(dst, src, LINK_POSITIVE);
	free(token->value.link.src);						//
	free(token->value.link.dst);						//
}

static t_bool	read_link(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_LINK)
	{
		if (ft_strcmp(token->value.link.src, token->value.link.dst) == 0)
			lem_die_at_line(lem, "a room cannot be linked to itself");
		add_link(lem, token);
	}
	return (token->type == TOKEN_LINK);
}

void			read_links(t_lem *lem, t_token *token)
{
	if (token->type != TOKEN_EOF && token->type != TOKEN_LINK)
		lem_die_at_line(lem, "invalid room or link");
	while (read_link(lem, token))
		get_next_token(lem, token);
}
