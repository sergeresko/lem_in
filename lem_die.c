/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_die.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:34:35 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/23 19:36:15 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//
#include <stdio.h>		// printf for debugging
//
//
#include <stdlib.h>		// exit
#include "lem_in.h"

void		lem_die_eof(char const *message)
{
	//
	// TODO: replace printf with ft_putstr_fd and print to STRERR
	printf("%s\n", message);
	//
	//
	exit(1);
}

void		lem_die(lem *lem, char const *message)
{
	//
	// TODO: replace printf with ft_putstr_fd and print to STRERR
	printf("ERROR at line %d: %s\n%s\n", lem->input->line_count, message, lem->input->tail->data);
	//
	//
	exit(1);
}
