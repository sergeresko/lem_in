/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:51:58 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 18:01:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_TOKEN_H
# define GET_NEXT_TOKEN_H

# include "datatypes.h"		// t_bool
//#include "lem_in.h"		// hence files that include "read_input.h" need not include "lem_in.h"

typedef enum e_type		t_type;
typedef struct s_move	t_move;
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

struct		s_move
{
	int		ant;
	char	*dst;
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
	struct	s_value_turn
	{
		int		len;
		t_move	*moves;
	}		turn;
};

struct		s_token
{
	t_type	type;
	t_value	value;
};

t_bool		ft_atoi_strict(char const *str, int *value);	// maybe out of here
void		tokenize_turn(char const *line, t_token *token);
void		tokenize(char const *line, t_token *token);

#endif
