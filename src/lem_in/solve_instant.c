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

#include "libft.h"
#include "lem_in.h"
#include "print.h"

static void		print_paths_instant(void)
{
	print_total("paths", 0);
	ft_putstr("#\n");
}

static void		print_moves_instant(void)
{
	ft_putstr("\n");
}

void			solve_instant(t_lem const *lem)
{
	if (lem->options.paths)
		print_paths_instant();
	if (lem->options.turns)
		print_total("turns", 0);
	if (lem->options.moves)
		print_moves_instant();
}
