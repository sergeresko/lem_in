/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:50:28 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/20 19:50:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc
#include "lem_in.h"

// TODO: +/- 1 to n_turns so that it makes sense

static void	fill_numbers(t_solution *s, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		s->numbers[j] = s->n_turns - s->paths[j].length;
		++j;
	}
	while (j < s->n_paths)
	{
		s->numbers[j] = 0;
		++j;
	}
}

/*
**	TODO: determine how many ants should walk each path
*/

static int	distribute_evenly(int n_ants, t_solution *s)
{
	int		i;
	int		d;

	i = 1;
	while (i < s->n_paths)
	{
		d = s->paths[i].length - s->paths[i - 1].length;
		if (n_ants / i <= d)
			break ;
		n_ants -= d * i;
		++i;
	}
	d = n_ants / i;
	n_ants -= d * i;
	s->n_turns = s->paths[i - 1].length + d;
	fill_numbers(s, i);
	return (n_ants);
}

static void	distribute_remainder(int n_ants, t_solution *s)
{
	int		i;

	if (n_ants == 0)
		s->n_turns -= 1;
	i = 0;
	while (n_ants--)
	{
		s->numbers[i] += 1;
		++i;
	}
}

void		distribute_ants(int n_ants, t_solution *s)
{
	n_ants = distribute_evenly(n_ants, s);
	distribute_remainder(n_ants, s);
}
