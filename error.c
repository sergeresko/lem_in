/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:52:11 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/23 12:57:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lem_die(void)
{
	static char	*messages[] = {
		"invalid number of ants (a non-negative integer expected)",
		"already has a start room",
		"already has an end room",
		"already has a room with this name",
		"invalid room (format: name coord_x coord_y)",
		"invalid link (format: name1-name2)",
		"already has a link between these rooms",
	};

	die_with_message();
	exit(1);
}
