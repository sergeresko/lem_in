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
	ft_printf(PF_GREEN"link_push (%s -> %s, %d)"PF_RESET":\n", src->name, dst->name, weight);
	ft_printf("    original %s->links: %#p, ", src->name, src->links);
	//
	// >
	l = malloc(sizeof(t_link));		// TODO: check memory
	l->dst = dst;
	l->weight = weight;
	glist_push(&src->links, _debug_addr = glist_new(l));	// glist_push_new(&src->links, l);
	// <
	//
	ft_printf("new link: "PF_GREEN"%#p"PF_RESET", new item: "PF_GREEN"%#p"PF_RESET", new %s->links: %#p\n", l, _debug_addr, src->name, src->links);
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
	ft_printf(PF_RED"link_pop"PF_RESET"(src: %#p) ", src);
	if (src->links == NULL)
		ft_printf("[%s has no links, "PF_RED"doing nothing]"PF_RESET"\n", src->name);
	//
	// >
	if (src->links == NULL)
		return (NULL);
	l = src->links->data;
	dst = l->dst;
	// <
	//
	ft_printf("item = %s->links: %#p, link = item->data: %#p ", src->name, src->links, l);
	ft_printf(PF_RED"[%s -> %s, %d]"PF_RESET":\n", src->name, dst->name, l->weight);
	//
	// >
	free(l);
	// <
	//
	ft_printf("    link freed, ");
	//
	// >
	glist_delete(&src->links);
	// <
	//
	ft_printf("item deleted, new %s->links: %#p\n", src->name, src->links);
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
		//
		//
		ft_printf("\033[35mfreeing link at %#p\033[0m\n", l);
		//
		//
		free(l);
		glist_delete(&src->links);
		return ;
	}
	links = src->links;
	while (links->next != NULL)
	{
		l = links->next->data;
		if (l->dst == dst)
		{
			//
			//
			ft_printf("\033[35mfreeing link at %#p\033[0m\n", l);
			//
			//
			free(l);
			glist_delete(&links->next);
			return ;
		}
		links = links->next;
	}
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
