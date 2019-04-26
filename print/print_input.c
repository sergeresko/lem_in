/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:45:32 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:07:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void		print_input(t_input const *input)
{
	t_glist	*lines;
	int		count;

	lines = input->lines;
	count = 0;
	while (lines != NULL)
	{
		ft_putstr(lines->data);
		ft_putchar('\n');
		lines = lines->next;
		++count;
	}
	if (count != input->line_count)
		lem_die_from_bug("line count mismatch");
}
