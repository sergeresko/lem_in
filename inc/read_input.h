/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:34:13 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 14:36:17 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include "get_next_token.h"
# include "lem_in.h"		// hence files that include "read_input.h" need not include "lem_in.h"

/*
**	`get_next_token` reads and saves lines from standard input until first
**		non-comment or end of file, constructs a respective token.
*/

void		get_next_token(t_lem *lem, t_token *token);

/*
**	The following functions read from standard input and perform necessary
**		operations. They start processing from the token passed to them and
**		upon termination leave a token to be processed further.
**
**	NOTE: `read_turns` is used only in the verifier.
*/

void		read_ants(t_lem *lem, t_token *token);
void		read_rooms(t_lem *lem, t_token *token);
void		read_links(t_lem *lem, t_token *token);
void		read_turns(t_lem *lem, t_token *token);

#endif
