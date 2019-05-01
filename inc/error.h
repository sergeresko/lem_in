/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:52:47 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 16:16:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "lem_in.h"		// t_lem

void		die(void);

void		error(char const *message);
void		error_nbr(char const *prefix, int number, char const *postfix);
void		error_at_line(t_lem const *lem, char const *message);
void		error_at_line_nbr(t_lem const *lem,
					char const *prefix, int number, char const *postfix);


#endif
