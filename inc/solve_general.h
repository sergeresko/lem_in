/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_general.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:25:43 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:33:54 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_GENERAL_H
# define SOLVE_GENERAL_H

# include "datatypes.h"

typedef struct s_path		t_path;
typedef struct s_solution	t_solution;

struct		s_path
{
	t_room	*origin;
	int		length;
//	int		ants;		// TODO: what is this?
};

struct		s_solution
{
	int		n_paths;
	t_path	*paths;
	int		*ants_per_path;
	int		n_turns;
};

t_bool		find_more_paths(t_graph *graph);
void		distribute_ants(int total_ants, t_solution *solution);
t_solution	*solution_build(int n_ants, t_room const *start, int n_paths);
void		solution_improve(t_solution **best_solution,
					int total_ants, t_room *start, int path_count);
void		solution_destroy(t_solution *solution);

#endif
