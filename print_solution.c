/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:21:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/20 19:27:23 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include <stdio.h>		// printf for debugging
//
//
#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

static int	add(t_room **loc, t_solution const *s)
{
	int		i;

	i = 0;
	while (i < s->n_paths && s->numbers[i] > 0)
	{
		s->numbers[i] -= 1;		// modifies solution, so const is misleading
		loc[i] = s->paths[i].origin;
		++i;
	}
	return (i);
}

static void	advance(t_room **loc, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		if (loc[i] != NULL)
			loc[i] = loc[i]->succ;		// ->... ?
		++i;
	}
}

static void	print_turn(t_room *const *loc, int k)
{
	int		first;		// t_bool
	int		i;

	first = 1;			// TRUE
	i = 0;
	while (i < k)
	{
		if (loc[i] != NULL)
		{
			if (!first)
				printf(" ");	// ft_putchar(' ');
			else
				first = 0;		// FALSE
			printf("L%d-%s", i + 1, loc[i]->name);		//
		}
		++i;
	}
	if (!first)				// Are these two lines
		printf("\n");		// still needed?
}

/*
**	TODO: [Description; what `loc` is for]
*/

void		print_solution(t_solution const *s, int n_ants)
{
	t_room	**loc;
	int		count;
	int		k;

	loc = malloc(n_ants * sizeof(t_room *));		// check memory
	count = s->n_turns;
	while (count--)
	{
		advance(loc, k);
		k += add(loc + k, s);
		print_turn(loc, k);
	}
	free(loc);
}
