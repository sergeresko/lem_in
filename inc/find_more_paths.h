/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_more_paths.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:16:48 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/26 14:17:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	the core algorithm of the project
*/

#ifndef FIND_MORE_PATHS_H
# define FIND_MORE_PATHS_H

# include "datatypes.h"

void		modify_graph(t_room *start, t_room *end);
t_bool		find_shortest_path(t_room *src, t_room *end);
void		restore_graph(t_room *start, t_room *end);
void		combine_paths(t_room *start, t_room *end);

#endif
