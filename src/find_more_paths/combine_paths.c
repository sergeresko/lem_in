/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:28:27 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/18 14:55:54 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"

/*
**	The set of paths described by `pred`/`succ` is overlaid with the path
**	that is described by `parent` fields and leads from `end` to `start`.
**
**	The paths in the first set are considered to be directed towards the end
**	and the latter path towards the start.
**
**	Overlaying means that if any two rooms are connected in either the first
**	set of paths or the latter path, this directed connection goes to the
**	result. If it is not present in either of them or is present in both (in
**	this case the connections have opposite directions), the result does not
**	contain it.
**
**	Fields `pred`/`succ` are modified in order to represent this new result.
*/

void			combine_paths(t_room *start, t_room *end)
{
	t_room		*a;
	t_room		*b;

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
