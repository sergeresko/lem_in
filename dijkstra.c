/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:05 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 19:50:32 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			dijkstra(t_room *src, t_room *end)		// t_bool
{
	t_set	*s;
	t_list	*links;
	t_link	*l;
	int		d;

	src->distance = 0;
	s = set_new();
	while (src != NULL && src != end)
	{
		links = src->links;
		while (links != NULL)
		{
			l = links->data;
			d = src->distance + l->weight;		// + ((t_link *)links->data)->weight
			if (d < l->dst->distance)
			{									// dst = ((t_link *)links->data)->dst
				l->dst->distance = d;
				l->dst->parent = src;
				set_add(s, l->dst);
			}
			links = links->next;
		}
		src = set_pop_min(s);		// if s is empty, returns NULL
	}
	set_destroy(&s);
	// return ...
}
