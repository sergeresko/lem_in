/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:06:31 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 14:06:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// verifier, the Very Fire of lem-in

// <
//
#include <stdlib.h>		// system
#include "libft.h"		// printing
//
// > 
#include "lem_in.h"

static void		print_help(void)
{
	ft_putstr("verifier, the Very Fire of lem-in (c) 2019 syeresko\n\n"
			"usage:  ./verifier [options] < lem_in_output\n"
			"        ./lem-in < filename | ./verifier [options]\n\n"
			"The verifier checks the solution provided by lem-in and, "
			"if it is correct,\nprints the total number of turns in it.\n\n"
			"Options:\n"
			"    -i, --input     also print the input\n"
			"    -h, --help      print only this help and quit\n");
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
	// print answer
	ft_putnbr(lem.input.turn_count);
	ft_putchar('\n');
	// <
	//
	system("leaks -q verifier >&2");
	//
	// >
	return (0);
}
