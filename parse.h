/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:51:58 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/21 18:02:51 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum e_type		t_type;
typedef union u_value	t_value;
typedef struct s_token	t_token;

enum		e_type
{
	TOKEN_COMMAND_START,
	TOKEN_COMMAND_END,
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

#endif
