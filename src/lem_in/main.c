/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:00:13 by syeresko          #+#    #+#             */
/*   Updated: 2019/05/07 15:56:07 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"
// <
//#include <stdlib.h>		// system
// > 
#include "lem_in.h"

static void		print_help(void)
{
	ft_putstr("lem-in (c) 2019 syeresko\n\n"
			"usage: ./lem-in [options] < filename\n\n"
			"Options indicate what to print:\n"
			"    -i, --input     raw input\n"
			"    -r, --rooms     rooms with their adjacency lists\n"
			"    -p, --paths     selected paths and ant distribution\n"
			"    -t, --turns     total number of turns\n"
			"    -m, --moves     lists of moves made at each turn\n"
			"    -h, --help      only this help\n"
			"If called without options, -i and -m are assumed.\n");
}

int				main(int argc, char **argv)
{
	t_lem		lem;

	// process options
	read_options(argc, argv, &lem.options);
	if (lem.options.help)
	{
		print_help();
		return (0);
	}
	// process input
	read_input(&lem);
	if (lem.options.input)
		print_input(&lem.input);
	if (lem.options.rooms)
		print_rooms(&lem.graph);
	// solve
	if (lem.total_ants == 0)
		solve_instant(&lem);
	else if (link_find(lem.graph.start, lem.graph.end) != NULL)
		solve_trivial(&lem);
	else
		solve_general(&lem);
	// <
	//system("leaks -q lem-in >&2");
	// >
	return (0);
}
