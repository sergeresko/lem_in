/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:04:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 20:19:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include "libft.h"		// for debugging
//
//
#include <stdlib.h>		// free, NULL
#include "lem_in.h"

/*
**	restore the path whose last room before `end` in the modified graph is `y`
**
**	TODO: [Description; get rid of `t`, replace by `end`]
*/

static void	restore_path(t_room *start, t_room *y, t_room *t)
{
	t_room	*x;
	t_room	*z;

	link_delete(t, y);
	while (y != start)
	{
		x = link_pop(y);
		z = link_pop(x);
		x->links = y->links;
		free(y);			// instead of room_destroy
		link_push(x, t, LINK_POSITIVE);		// t == x->succ
		link_push(t, x, LINK_POSITIVE);		// t == x->succ
		t = x;
		y = z;
	}
	link_push(start, t, LINK_POSITIVE);		// t == x
	link_push(t, start, LINK_POSITIVE);		// t == x
}

/*
**	restore every path that had been described by `pred`/`succ`
*/

void		restore_graph(t_room *start, t_room *end)
{
	t_glist	*links;
	t_link	*l;

	// <
	//
	ft_printf("\033[36m< restore_graph finished\033[0m\n");
	//
	// >
	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		// <
		//
		ft_printf("\033[36ml = %#p\033[0m\n", l);
		//
		// >
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(start, l->dst, end);
	}
	// <
	//
	ft_printf("\033[36m> restore_graph finished\033[0m\n");
	//
	// >
}
