/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:35:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include <stddef.h>

// TODO:
# define INFINITY		123456

typedef enum e_bool		t_bool;

typedef struct s_glist	t_glist;
typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_graph	t_graph;

typedef struct s_set	t_set;

/*
**	logical type
*/

enum		e_bool
{
	FALSE = 0,
	TRUE = 1,
};

/*
**	TODO: rename to t_list
**	generic singly-linked list
**
**	`glist_push` prepends a new item containing the specified data.
**	`glist_pop` deletes the first item and returns its data.
**
**	The trick to insert or remove an item in the middle or end of a list,
**	say right after an item pointed to by `t_glist *item`, is to pass
**	`&item->next` as the `head` parameter to these functions.
*/

struct		s_glist
{
	void	*data;
	t_glist	*next;
};

t_glist		*glist_new(void *data);			// TODO: to be removed
void		glist_push(t_glist **head, void *data);
void		*glist_pop(t_glist **head);

/*
**	TODO: describe
**	name, x, y
**	links
**	distance, parent - find_shortest_path
**	pred, succ
**	...
*/

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

t_room		*room_new(void);
t_room		*room_find(t_glist const *rooms, char const *room_name);

/*
**	weighted directed link between rooms
**
**	TODO: describe
**	`link_push` creates a new link and prepends an item...
*/

struct		s_link
{
	t_room	*dst;
	int		weight;
};

# define LINK_POSITIVE	1
# define LINK_ZERO		0
# define LINK_NEGATIVE	(-1)

void		link_push(t_room *src, t_room *dst, int weight);
t_room		*link_pop(t_room *src);
void		link_delete(t_room *src, t_room *dst);
t_link		*link_find(t_room *src, t_room *dst);		// currently used only when parsing

/*
**	list of rooms with designated start and end
*/

struct		s_graph
{
	t_glist	*rooms;
	t_room	*start;
	t_room	*end;
};

/*
**	set of rooms
**
**	TODO: describe
*/

struct		s_set
{
	t_glist	*elements;
};

t_set		*set_new(void);
void		set_push(t_set *s, t_room *x);
t_room		*set_pop_min(t_set *s);
void		set_destroy(t_set **s);

#endif
