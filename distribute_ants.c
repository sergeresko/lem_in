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

void		distribute_ants(int n_ants, t_solution *s)
{
	int		i;
	int		d;

	i = 0;
	while (++i < s->n_paths)
	{
		d = s->paths[i].length - s->paths[i - 1].length;
		if (n_ants / i <= d)
			break ;
		n_ants -= d * i;
	}
	d = n_ants / i;
	n_ants -= d * i;
	s->n_turns = s->paths[i - 1].length + d;
	fill_numbers(s, i);
	if (n_ants == 0)
		s->n_turns -= 1;
	i = 0;
	while (n_ants--)
	{
		s->numbers[i] += 1;
		++i;
	}
}
