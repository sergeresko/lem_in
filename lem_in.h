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

// TODO:
# define INFINITY		123456

# define LINK_POSITIVE	1
# define LINK_ZERO		0
# define LINK_NEGATIVE	(-1)

typedef enum e_bool		t_bool;

enum		e_bool
{
	FALSE = 0,
	TRUE = 1,
};

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
t_link		*link_find(t_room *src, t_room *dst);		// currently used only when parsing

// -----------------------------

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
	t_glist	*lines;
	t_glist	*last;
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
t_solution	*build_solution(int n_ants, t_room *start, int n_paths);
void		solution_destroy(t_solution *s);
void		print_solution(t_solution const *s, int n_ants);
void		print_total(t_solution const *s);
// -----------------------------

void		modify_graph(t_room *start, t_room *end);
void		restore_graph(t_room *start, t_room *end);
void		xor_paths(t_room *start, t_room *end);
int			bhandari(t_graph *g);	// t_bool

// -----------------------------
void		lem_die(char const *message);
void		lem_die_at_line(t_lem const *lem, char const *message);
void		lem_die_from_bug(char const *message);




void		print_input(t_input const *input);
void		print_rooms(t_graph const *g);
void		print_paths(t_solution const *s, t_room const *start);
void		print_solution(t_solution const *s, int n_ants);

#endif
