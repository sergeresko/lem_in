/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:35:42 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 12:38:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "lem_in.h"
#include "error.h"

static void		print_usage(void)
{
	ft_putstr_fd("usage: ./lem-in [options] < filename\n\n"
			"See `./lem-in --help` for the list of options.\n",
			STDERR_FILENO);
	die();
}

static void		read_abbreviations(char const *arg, t_opt *options)
{
	char		c;

	if (arg[1] == '\0')
		print_usage();
	while ((c = *(++arg)))
	{
		if (c == 'h')
			options->help = TRUE;
		else if (c == 'i')
			options->input = TRUE;
		else if (c == 'r')
			options->rooms = TRUE;
		else if (c == 'p')
			options->paths = TRUE;
		else if (c == 't')
			options->turns = TRUE;
		else if (c == 'm')
			options->moves = TRUE;
		else
			print_usage();
	}
}

static void		read_arguments(char *const *argv, t_opt *options)
{
	char		*arg;

	while ((arg = *(++argv)))
	{
		if (arg[0] == '-')
		{
			if (ft_strcmp(arg, "--help") == 0)
				options->help = TRUE;
			else if (ft_strcmp(arg, "--input") == 0)
				options->input = TRUE;
			else if (ft_strcmp(arg, "--rooms") == 0)
				options->rooms = TRUE;
			else if (ft_strcmp(arg, "--paths") == 0)
				options->paths = TRUE;
			else if (ft_strcmp(arg, "--turns") == 0)
				options->turns = TRUE;
			else if (ft_strcmp(arg, "--moves") == 0)
				options->moves = TRUE;
			else
				read_abbreviations(arg, options);
		}
		else
			print_usage();
	}
}

void			read_options(int argc, char *const *argv, t_opt *options)
{
	options->help = FALSE;
	options->rooms = FALSE;
	options->paths = FALSE;
	options->turns = FALSE;
	if (argc > 1)
	{
		options->input = FALSE;
		options->moves = FALSE;
		read_arguments(argv, options);
	}
	else
	{
		options->input = TRUE;
		options->moves = TRUE;
	}
}
