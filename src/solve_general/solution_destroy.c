/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:17:53 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/30 15:18:45 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	
#include "solve_general.h"

void			solution_destroy(t_solution *solution)
{
	free(solution->paths);
	free(solution->ants_per_path);
	free(solution);
} 
