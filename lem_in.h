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
	int		input;
	int		rooms;
	int		paths;
	int		moves;
	int		total;
};

struct		s_input
{
	int		line_count;
	t_list	*lines;
	t_list	*last;
};

struct		s_lem
{
	t_opt	options;
	t_input	input;
	int		total_ants;
	t_graph	graph;
};

void		read_options(int argc, char *const *argv, t_opt *options);
void		read_input(t_lem *lem);

// -----------------------------

typedef struct s_path	t_path;
typedef struct s_solution	t_solution;

struct	s_path
{
	t_room	*origin;
	int		length;
	int		ants;		// TODO: what is this?
};

struct	s_solution
{
	int		n_paths;
	t_path	*paths;
	int		*ants_per_path;
	int		n_turns;
};

void		distribute_ants(int n_ants, t_solution *s);
t_solution	*build_solution(int n_ants, t_room const *start, int n_paths);
void		solution_destroy(t_solution *s);

// -----------------------------

t_bool		find_more_paths(t_graph *g);

// -----------------------------

void		lem_die(char const *message);
void		lem_die_at_line(t_lem const *lem, char const *message);
void		lem_die_from_bug(char const *message);




void		print_input(t_input const *input);
void		print_rooms(t_graph const *g);
void		print_paths(t_solution const *s, t_room const *start);
void		print_moves(t_solution const *s, int n_ants);
void		print_total(t_solution const *s);

#endif
