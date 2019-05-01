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

void		print_total(char const *str, int number)
{
	ft_putstr("#\n#   Total ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(number);
	ft_putstr("\n#\n");
}
