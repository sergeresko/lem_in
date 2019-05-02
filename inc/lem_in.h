/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:35:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "datatypes.h"

typedef struct s_opt	t_opt;
typedef struct s_input	t_input;
typedef struct s_lem	t_lem;

struct		s_opt
{
	int		help;
	int		input;
	int		rooms;
	int		paths;
	int		turns;
	int		moves;
};

struct		s_input
{
	int		line_count;
	t_list	*lines;
	t_list	*last;
	int		turn_count;		// added for verifier
};

struct		s_lem
{
	t_opt	options;
	t_input	input;
	int		total_ants;
	t_graph	graph;
	t_room	**loc;			// added for verifier
};

/*
**	NOTE: The following pair of functions has different implementations for
**		`lem-in` and `verifier`.
*/

void		read_options(int argc, char *const *argv, t_opt *options);
void		read_input(t_lem *lem);

/*
**	`solve_instant` prints the solution when there are no ants.
**	`solve_trivial` prints the solution when the start and the end are directly
**		connected.
**	`solve_general` finds and prints the solution in other cases.
*/

void		solve_instant(t_lem const *lem);
void		solve_trivial(t_lem const *lem);
void		solve_general(t_lem *lem);

#endif
