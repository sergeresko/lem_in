/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:09:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:23:00 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "datatypes.h"

void		print_path(int n_ants, int length,
					t_room const *start, t_room const *origin)
{
	ft_putstr("#   ");
	ft_putnbr(n_ants);
	ft_putstr(" ant");
	if (n_ants != 1)
		ft_putchar('s');
	ft_putstr(" to path of length ");
	ft_putnbr(length);
	ft_putstr(" [ ");		// TODO:
	ft_putstr(start->name);
	while (origin != NULL)
	{
		ft_putchar(' ');
		ft_putstr(origin->name);
		origin = origin->best_succ;		// ->...
	}
	ft_putstr(" ]\n");		// TODO:
}
