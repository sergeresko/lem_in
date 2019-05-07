/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:34:35 by syeresko          #+#    #+#             */
/*   Updated: 2019/05/07 15:55:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

#define ANSI_BOLD	"\033[1m"
#define ANSI_RESET	"\033[0m"

void		die(void)
{
	// <
	//system("leaks -q lem-in >&2");
	//system("leaks -q verifier >&2");
	// >
	exit(1);
}

void		error(char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	die();
}

void		error_nbr(char const *prefix, int number, char const *postfix)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putnbr_fd(number, STDERR_FILENO);
	ft_putstr_fd(postfix, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	die();
}

void		error_at_line(t_lem const *lem, char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR at line ", STDERR_FILENO);
	ft_putnbr_fd(lem->input.line_count, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	ft_putstr_fd(lem->input.last->data, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	die();
}

void		error_at_line_nbr(t_lem const *lem,
					char const *prefix, int number, char const *postfix)
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
	die();
}
