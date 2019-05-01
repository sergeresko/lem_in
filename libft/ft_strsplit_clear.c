/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:50:45 by syeresko          #+#    #+#             */
/*   Updated: 2019/03/31 12:51:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	Free each element of a NULL-termainated array `tab` as well as `tab` itself.
*/

void		ft_strsplit_clear(char **tab)
{
	char	**p;

	p = tab;
	while (*p)
		free(*(p++));
	free(tab);
}
