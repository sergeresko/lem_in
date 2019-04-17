/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:19:36 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 20:40:45 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

// TODO:
# define INFINITY		123456

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

t_glist		*glist_new(void const *data);
void		glist_push(t_glist **head, t_glist *elem);
void		glist_delete(t_glist **elem);

void		link_push(t_room *src, t_room const *dst, int weight);
t_room		*link_pop(t_room *src);
void		link_delete(t_room *src, t_room *dst);

#endif
