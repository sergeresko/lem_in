/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:28:27 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 17:31:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		xor_paths(t_room *start, t_room *end)
{
	t_room	*a;
	t_room	*b;

	b = end;
	while ((a = b->parent) != NULL)
	{
		if (a->pred != b && b->succ != a)
		{
			if (a != start)
				a->succ = b;
			if (b != end)
				b->pred = a;
		}
		else
		{
			if (a->pred == b)
				a->pred = NULL;
			if (b->succ == a)
				b->succ = NULL;
		}
		b = a;
	}
}