/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:52:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/25 19:44:56 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// {
#ifdef DEBUG
# include "libft.h"		// for debugging
#endif
// }
#include <stdlib.h>		// NULL
#include "datatypes.h"
// {
#ifdef DEBUG
# define DEBUG_PTR(ptr) (((unsigned long long)(ptr) & 0xfffff0) >> 4)
#endif
// }

/*
**	modify the path whose last room before `end` is `x`
**
**	TODO: [Description]
*/

static void	modify_path(t_room *start, t_room *x, t_room *end)
{
	t_room	*y;

	link_delete(end, x);
	while (x != start)
	{
		link_delete(x, x->succ);
		link_delete(x, x->pred);
		y = room_new();				//
		y->links = x->links;
		x->links = NULL;
		link_push(x->succ, y, LINK_NEGATIVE);
		link_push(y, x, LINK_ZERO);
		if (x->pred == start)
		{
			link_delete(start, x);
			link_push(x, start, LINK_NEGATIVE);
			// break;
		}
		x = x->pred;
	}
}

/*
**	modify every path described by `pred`/`succ`
*/

void		modify_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

// {
#ifdef DEBUG
	ft_printf("\033[36m< modify_graph started\033[0m\n");
#endif
// }
	links = end->links;
	while (links != NULL)
	{
		l = links->data;
// {
#ifdef DEBUG
		ft_printf("\033[36ml = %05x\033[0m\n", DEBUG_PTR(l));
#endif
// }
		links = links->next;
		if (l->dst->succ == end)
			modify_path(start, l->dst, end);
	}
// {
#ifdef DEBUG
	ft_printf("\033[36m> modify_graph finished\033[0m\n", l);
#endif
// }
}
