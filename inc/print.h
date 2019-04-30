/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:42:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:44:57 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "lem_in.h"
# include "solve_general.h"

void		print_input(t_input const *input);
void		print_moves(t_solution const *s, int total_ants);
void		print_paths(t_solution const *s, t_room const *start);
void		print_rooms(t_graph const *graph);
void		print_total(t_solution const *s);


#endif
