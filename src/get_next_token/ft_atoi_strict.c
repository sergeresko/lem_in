/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:30:30 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 11:33:46 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"

t_bool		ft_atoi_strict(char const *str, int *number)
{
	int		sign;
	int		abs;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	if (*str == '\0')
		return (FALSE);
	abs = 0;
	while ('0' <= *str && *str <= '9')
	{
		abs = abs * 10 + (int)(*(str++) - '0');
		if (abs < 0 && !(abs == INT_MIN && *str == '\0'))
			return (FALSE);
	}
	if (*str)
		return (FALSE);
	*number = sign * abs;
	return (TRUE);
}
