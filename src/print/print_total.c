/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:32:42 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:35:13 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void		print_total(t_solution const *s)
{
	ft_putstr("#\n#   Total turns: ");
	ft_putnbr(s->n_turns);
	ft_putstr("\n#\n");
}
