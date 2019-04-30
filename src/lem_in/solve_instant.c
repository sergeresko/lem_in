/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_instant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:11:01 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:11:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		// for printing
#include "lem_in.h"

static void		print_paths_instant(void)
{
	ft_putstr("#\n#   Paths:\n#\n");
	// TODO: number of paths: 0
	ft_putstr("#\n");
}

static void		print_total_instant(void)
{
	// TODO: make just a single string
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(0);
	ft_putstr("\n#\n");
}

static void		print_moves_instant(void)
{
	ft_putstr("\n");
}

// if there are zero ants
void			solve_instant(t_lem const *lem)
{
	if (lem->options.paths)
		print_paths_instant();
	if (lem->options.total)
		print_total_instant();
	if (lem->options.moves)
		print_moves_instant();
}
