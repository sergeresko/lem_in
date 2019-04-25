/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:04:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/25 19:49:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// {
#ifdef DEBUG
# include "libft.h"	// for debugging
#endif
// }
#include <stdlib.h>		// free, NULL
#include "lem_in.h"
// {
#ifdef DEBUG
# define DEBUG_PTR(ptr) (((unsigned long long)(ptr) & 0xfffff0) >> 4)
#endif
// }

/*
**	restore the path whose last room before `end` in the modified graph is `y`
**
**	TODO: [Description; get rid of `t`, replace by `end`]
*/

static void	restore_path(t_room *start, t_room *y, t_room *end)
{
	t_room	*x;
	t_room	*z;

	link_delete(end, y);
	while (y != start)
	{
		x = link_pop(y);
		z = link_pop(x);
		x->links = y->links;
		free(y);			// instead of room_destroy
// {
#ifdef DEBUG
		ft_printf(PF_YELLOW"[free %05x (room)]"PF_RESET, DEBUG_PTR(y));	//
#endif
// }
		link_push(x, x->succ, LINK_POSITIVE);		// t == x->succ
		link_push(x->succ, x, LINK_POSITIVE);		// t == x->succ
//		t = x;
		y = z;
	}
	link_push(start, x, LINK_POSITIVE);		// t == x
	link_push(x, start, LINK_POSITIVE);		// t == x
}

/*
**	restore every path that had been described by `pred`/`succ`
*/

void		restore_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

// {
#ifdef DEBUG
	ft_printf(PF_CYAN"< restore_graph started"PF_RESET"\n");
#endif
// }
	links = end->links;
	while (links != NULL)
	{
		l = links->data;
// {
#ifdef DEBUG
		ft_printf(PF_CYAN"l = %05x"PF_RESET"\n", DEBUG_PTR(l));
#endif
// }
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(start, l->dst, end);
	}
// {
#ifdef DEBUG
	ft_printf(PF_CYAN"> restore_graph finished"PF_RESET"\n");
#endif
// }
}
