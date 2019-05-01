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

// <
//
#include <stdlib.h>		// system
#include "libft.h"		// printing
//
// > 
#include "lem_in.h"

int			main(int argc, char **argv)
{
	t_lem	lem;

	// process options
	(void)argc;
	(void)argv;
//	read_options(argc, argv, &lem.options);
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
	// print answer
	ft_putnbr(lem.input.turn_count);
	ft_putchar('\n');
	// <
	//
//	system("leaks -q verifier");
	//
	// >
	return (0);
}
