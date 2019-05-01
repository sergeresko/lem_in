/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:07:20 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 14:11:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include "error.h"

void		read_ants(t_lem *lem, t_token *token)
{
	if (token->type == TOKEN_EOF)
		error("number of ants is missing");
	if (token->type != TOKEN_ANTS)
		error_at_line(lem,
			"invalid number of ants (a non-negative integer expected)");
	lem->total_ants = token->value.ants;
	get_next_token(lem, token);
}
