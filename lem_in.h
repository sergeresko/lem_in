/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/20 19:52:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// TODO:
# define INFINITY		123456

# define LINK_POSITIVE	1
# define LINK_ZERO		0
# define LINK_NEGATIVE	(-1)

typedef struct s_glist	t_glist;
typedef struct s_room	t_room;
typedef struct s_graph	t_graph;
typedef struct s_link	t_link;

struct		s_glist
{
	void	*data;
	t_glist	*next;
};

struct		s_room
{
	char	*name;
	int		x;
	int		y;
	t_glist	*links;
	int		distance;
	t_room	*parent;
	t_room	*pred;
	t_room	*succ;
};

struct		s_graph
{
	t_glist	*rooms;
	t_room	*start;
	t_room	*end;
};

struct		s_link
{
	t_room	*dst;
	int		weight;
};

t_glist		*glist_new(void *data);
void		glist_push(t_glist **head, t_glist *elem);
void		glist_delete(t_glist **elem);

t_room		*room_new(void);

void		link_push(t_room *src, t_room *dst, int weight);
t_room		*link_pop(t_room *src);
void		link_delete(t_room *src, t_room *dst);

// -----------------------------
typedef struct s_set	t_set;

struct		s_set
{
	t_glist	*elements;
};

t_set		*set_new(void);
void		set_push(t_set *s, t_room *x);
t_room		*set_pop_min(t_set *s);
void		set_destroy(t_set **s);

int			dijkstra(t_room *src, t_room *end);		// t_bool
// -----------------------------

// -----------------------------
typedef struct s_path	t_path;
typedef struct s_solution	t_solution;

struct	s_path
{
	t_room	*origin;
	int		length;
	int		ants;
};

struct	s_solution
{
	int		n_paths;
	t_path	*paths;
	int		*numbers;
	int		n_turns;
};

void		distribute_ants(int n_ants, t_solution *s);
t_solution	*build_solution(int n_ants, t_room *start, int n_paths);
void		solution_destroy(t_solution *s);
void		print_solution(t_solution const *s, int n_ants);
// -----------------------------

void		modify_graph(t_room *start, t_room *end);
void		restore_graph(t_room *start, t_room *end);
void		xor_paths(t_room *start, t_room *end);
int			bhandari(t_graph *g);	// t_bool

#endif
