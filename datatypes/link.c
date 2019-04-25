/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:42:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 20:13:55 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// <
//
#include "libft.h"		// debugging
//
// >
#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

// <
//
#define DEBUG_PTR(ptr) (((unsigned long long)(ptr) & 0xfffff0) >> 4)
//
// >

/*
**	to the list of links from room `src` prepend a new link to room `dst`
**	of specified weight
*/

void		link_push(t_room *src, t_room *dst, int weight)
{
	t_link	*l;
	void	*_debug_addr;	//

	// <
	//
	ft_printf(PF_GREEN"%s -> %s (%d)"PF_RESET": ", src->name, dst->name, weight);
	ft_printf("old %s->links %05x, ", src->name, DEBUG_PTR(src->links));
	//
	// >
	l = malloc(sizeof(t_link));		// TODO: check memory
	l->dst = dst;
	l->weight = weight;
	glist_push(&src->links, _debug_addr = glist_new(l));	// glist_push_new(&src->links, l);
	// <
	//
	ft_printf("link "PF_GREEN"%05x"PF_RESET", item "PF_GREEN"%05x"PF_RESET"\n", DEBUG_PTR(l), DEBUG_PTR(_debug_addr));
	if (_debug_addr != src->links)
		lem_die_from_bug("2019/04/24 19:38");
	//
	// >
}

/*
**	remove the first link from room `src` and return that link's destination
*/

t_room		*link_pop(t_room *src)
{
	t_link	*l;
	t_room	*dst;

	// <
	//
	if (src->links == NULL)
		ft_printf("[%s has no links, "PF_RED"doing nothing"PF_RESET"]\n", src->name);
	//
	// >
	if (src->links == NULL)
	{
		lem_die_from_bug("popping an empty list");
		return (NULL);
	}
	l = src->links->data;
	dst = l->dst;
	// <
	//
	ft_printf(PF_RED"%s -> %s (%d)"PF_RESET": ", src->name, dst->name, l->weight);
	ft_printf("item "PF_RED"%05x"PF_RESET", link "PF_RED"%05x"PF_RESET", ", DEBUG_PTR(src->links), DEBUG_PTR(l));
	//
	// >
	free(l);
	glist_delete(&src->links);
	// <
	//
	ft_printf("new %s->links %05x\n", src->name, DEBUG_PTR(src->links));
	//
	// >
	return (dst);
}

/*
**	remove the link from room `src` to room `dst`
*/

void		link_delete(t_room *src, t_room *dst)
{
	t_glist	*links;
	t_link	*l;

	l = src->links->data;
	if (l->dst == dst)
	{
		// <
		//
		ft_printf(PF_MAGENTA"%s -> %s (%d)"PF_RESET": ", src->name, dst->name, l->weight);
		ft_printf("old %s->links %05x, link "PF_MAGENTA"%05x"PF_RESET", item "PF_MAGENTA"%05x"PF_RESET,
				src->name, DEBUG_PTR(src->links), DEBUG_PTR(l), DEBUG_PTR(src->links));
		//
		// >
		free(l);
		// <
		//
		ft_putstr(", ");
		//
		// >
		glist_delete(&src->links);
		// <
		//
		ft_printf("new %s->links %05x\n", src->name, DEBUG_PTR(src->links));
		//
		// >
		return ;
	}
	links = src->links;
	while (links->next != NULL)
	{
		l = links->next->data;
		if (l->dst == dst)
		{
			// <
			//
			ft_printf(PF_MAGENTA"%s -> %s (%d)"PF_RESET": ", src->name, dst->name, l->weight);
			ft_printf("old %s->links %05x, link "PF_MAGENTA"%05x"PF_RESET", item "PF_MAGENTA"%05x"PF_RESET",",
					src->name, DEBUG_PTR(src->links), DEBUG_PTR(l), DEBUG_PTR(links->next));
			//
			// >
			free(l);
			// <
			//
			ft_putstr(" ");
			//
			// >
			glist_delete(&links->next);		// <-- TODO: the bug is here
			// <
			//
			ft_printf("new %s->links %05x\n", src->name, DEBUG_PTR(src->links));
			//
			// >
			return ;
		}
		links = links->next;
	}
	lem_die_from_bug("no link to delete");
}

/*
**	return the link from `src` to `dst` if it exists or NULL otherwise
*/

t_link		*link_find(t_room *src, t_room *dst)
{
	t_glist	*links;
	t_link	*l;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		if (l->dst == dst)
			return (l);
		links = links->next;
	}
	return (NULL);
}
