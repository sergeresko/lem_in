/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:41:32 by syeresko          #+#    #+#             */
/*   Updated: 2018/10/25 14:30:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void			*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*cast_dst;
	char const	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (char const *)src;
	while (n--)
		*(cast_dst++) = *(cast_src++);
	return (dst);
}
