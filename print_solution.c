/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:21:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/20 15:58:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include <stdio.h>		// printf for debugging
//
//
#include <stdlib.h>		// malloc, free, NULL
#include "lem_in.h"

static int	add(t_room **loc, t_path **paths, int n_paths)
{
	int		i;

	i = 0;
	while (i < n_paths && paths[i]->ants > 0)
	{
		paths[i]->ants -= 1;
		loc[i] = paths[i]->origin;
		++i;
	}
	return (i);
}

static int	advance(t_room **loc, int k)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < k)
	{
		if (loc[i] != NULL)
		{
			loc[i] = loc[i]->succ;		// ->... ?
			++count;
		}
		++i;
	}
	return (count);
}

static void	print_turn(t_room **loc, int k)
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
			printf("L%d-%s", i + 1, loc[i]->name);
		}
		++i;
	}
	if (!first)
		printf("\n");
}

void		print_solution(t_path **paths, int n_paths, int n_ants)
{
	t_room	*(*loc);
	int		k;

	loc = malloc(n_ants * sizeof(t_room *));		// check memory
	k = add(loc, paths, n_paths);
	print_turn(loc, k);
	while (advance(loc, k) > 0)
	{
		k += add(loc + k, paths, n_paths);
		print_turn(loc, k);
	}
	free(loc);
}
