/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_die.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:34:35 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 15:16:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// exit
#include <unistd.h>		// STDERR_FILENO
#include "libft.h"
#include "lem_in.h"

#define ANSI_BOLD	"\033[1m"
#define ANSI_RESET	"\033[0m"

void		lem_die(char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	exit(1);
}

void		lem_die_number(char const *prefix, int number, char const *postfix)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putnbr_fd(number, STDERR_FILENO);
	ft_putstr_fd(postfix, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	exit(1);
}

void		lem_die_at_line(t_lem const *lem, char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR at line ", STDERR_FILENO);
	ft_putnbr_fd(lem->input.line_count, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	ft_putstr_fd(lem->input.last->data, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

void		lem_die_at_line_number(t_lem const *lem, char const *prefix,
		int number, char const *postfix)
{
	ft_putstr_fd(ANSI_BOLD"ERROR at line ", STDERR_FILENO);
	ft_putnbr_fd(lem->input.line_count, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putnbr_fd(number, STDERR_FILENO);
	ft_putstr_fd(postfix, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	ft_putstr_fd(lem->input.last->data, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}


// TODO: to be removed
void		lem_die_from_bug(char const *message)
{
	ft_putstr_fd("\033[1;31mBUG: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\033[0m\n", STDERR_FILENO);
	exit(1);
}
