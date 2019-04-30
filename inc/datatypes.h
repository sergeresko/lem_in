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
# include <limits.h>

# define INFINITY		INT_MAX

typedef enum e_bool		t_bool;

typedef struct s_list	t_list;
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
**	generic singly-linked list
**
**	`list_push` prepends a new item containing the specified data.
**	`list_pop` deletes the first item and returns its data.
**
**	The trick to insert or remove an item in the middle or end of a list,
**	say right after an item pointed to by `t_list *item`, is to pass
**	`&item->next` as the `head` parameter to these functions.
*/

struct		s_list
{
	void	*data;
	t_list	*next;
};

void		list_push(t_list **head, void *data);
void		*list_pop(t_list **head);

/*
**	TODO: describe
**	name, x, y
**	links
**	distance, parent - find_shortest_path
**	pred, succ
**	...
**	`room_new` allocates and initializes a room.
**	`room_find` returns a room by its name or NULL if it is not in the list.
*/

struct		s_room
{
	char	*name;
	int		x;
	int		y;
	t_list	*links;
	int		distance;
	t_room	*parent;
	t_room	*pred;
	t_room	*succ;
	t_room	*best_succ;		// TODO: added
};

t_room		*room_new(void);
t_room		*room_find(t_list const *rooms, char const *room_name);

/*
**	weighted directed link between rooms
**
**	`link_push` creates a new link to `dst` of specified weight
**		and prepends it to the list of links from `src`.
**	`link_pop` removes the room's first link and returns its destination
**		(`src` must have at least one link).
**	`link_delete` removes the link to `dst` from `src` (the link must
**		actually exist).
**	`link_find` returns the link between the given rooms or NULL if they
**		are not linked.
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
t_link		*link_find(t_room const *src, t_room const *dst);

/*
**	list of rooms with designated start and end
*/

struct		s_graph
{
	t_list	*rooms;
	t_room	*start;
	t_room	*end;
};

/*
**	set of rooms
**
**	`set_new` returns a new empty set.
**	`set_push` includes a room in the set if it is not already there.
**	`set_pop_min` excludes from the set and returns a room with the smallest
**		distance; if the set is empty, does nothing and returns NULL.
**	`set_destroy` empties and deletes the set.
*/

struct		s_set
{
	t_list	*elements;
};

t_set		*set_new(void);
void		set_push(t_set *set, t_room *room);
t_room		*set_pop_min(t_set *set);
void		set_destroy(t_set *set);

#endif
