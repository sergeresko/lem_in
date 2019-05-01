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
# include "solve_general.h"		// for print_moves

void		print_input(t_input const *input);
void		print_rooms(t_graph const *graph);
void		print_total(char const *str, int number);
void		print_path(int n_ants, int length,
					t_room const *start, t_room const *origin);
void		print_moves(t_solution const *solution, int total_ants);

#endif
