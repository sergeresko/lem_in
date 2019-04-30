/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:00:13 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 18:00:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
// <
//
#include <stdlib.h>		// system
//
// > 
#include "lem_in.h"

int			main(int argc, char **argv)
{
	t_lem	lem;

	// process options
	read_options(argc, argv, &lem.options);
	// TODO: help
	/*
	if (lem.options.help)
	{
		print_help();
		return (0);
	}
	*/
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
	//
//	system("leaks -q lem-in");
	//
	// >
	return (0);
}
