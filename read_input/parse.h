/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:51:58 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 11:33:41 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "lem_in.h"		// hence files that include "parse.h" need not include "lem_in.h"

typedef enum e_type		t_type;
typedef union u_value	t_value;
typedef struct s_token	t_token;

enum		e_type
{
	TOKEN_CMD_START,
	TOKEN_CMD_END,
	TOKEN_COMMENT,
	TOKEN_TURN,
	TOKEN_ROOM,
	TOKEN_LINK,
	TOKEN_ANTS,
	TOKEN_EMPTY_LINE,
	TOKEN_ERROR,
	TOKEN_EOF,
};

union		u_value
{
	int		ants;
	struct	s_value_room
	{
		char	*name;
		int		x;
		int		y;
	}		room;
	struct	s_value_link
	{
		char	*src;
		char	*dst;
	}		link;
};

struct		s_token
{
	t_type	type;
	t_value	value;
};

int			ft_atoi_strict(char const *str, int *value);	// t_bool

void		tokenize(char const *str, t_token *token);

t_room		*find_room(t_glist *rooms, char const *room_name);

void		lem_die(t_lem *lem, char const *message);
void		lem_die_eof(char const *message);
void		get_next_token(t_lem *lem, t_token *token);
void		read_ants(t_lem *lem, t_token *token);
void		read_rooms(t_lem *lem, t_token *token);
void		read_links(t_lem *lem, t_token *token);

#endif
