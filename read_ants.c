/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:07:20 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/23 19:33:56 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parse.h"

void		read_ants(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_EOF)
		lem_die_eof("number of ants is missing");
	if (token->type != TOKEN_ANTS)
		lem_die(lem, "invalid number of ants (a non-negative integer expected)");
	lem->total_ants = token->value.ants;
	get_next_token(lem, token);
}
