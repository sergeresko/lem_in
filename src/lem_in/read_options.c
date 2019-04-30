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

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "lem_in.h"

#define USAGE	"usage: ./lem-in [OPTIONS] < <filename>"

static void	print_usage(void)
{
	ft_putstr_fd(USAGE "\n\n"
		"See `./lem-in --help` for the list of options.\n",
		STDERR_FILENO);
	exit(1);
}

static void	print_help(void)
{
	ft_putstr(USAGE "\n\n"
		"Options indicate what to print:\n"
		"    -i, --input     raw input\n"
		"    -r, --rooms     rooms with their neighbor lists\n"
		"    -p, --paths     selected paths and ant distribution\n"
		"    -L, --moves     lists of moves made at each turn\n"
		"    -n, --total     total number of turns\n"
		"    -h, --help      only this help\n"
		"If called without options, -i and -L are assumed.\n");
	exit(0);
}

static void	read_abbreviations(char const *arg, t_opt *options)
{
	char	c;

	if (arg[1] == '\0')
		print_usage();
	while ((c = *(++arg)))
	{
		if (c == 'h')
			print_help();
		else if (c == 'i')
			options->input = TRUE;
		else if (c == 'r')
			options->rooms = TRUE;
		else if (c == 'p')
			options->paths = TRUE;
		else if (c == 'L')
			options->moves = TRUE;
		else if (c == 'n')
			options->total = TRUE;
		else
			print_usage();
	}
}

static void	read_arguments(char *const *argv, t_opt *options)
{
	char	*arg;

	while ((arg = *(++argv)))
	{
		if (arg[0] == '-')
		{
			if (ft_strcmp(arg, "--help") == 0)
				print_help();
			else if (ft_strcmp(arg, "--input") == 0)
				options->input = TRUE;
			else if (ft_strcmp(arg, "--rooms") == 0)
				options->rooms = TRUE;
			else if (ft_strcmp(arg, "--paths") == 0)
				options->paths = TRUE;
			else if (ft_strcmp(arg, "--moves") == 0)
				options->moves = TRUE;
			else if (ft_strcmp(arg, "--total") == 0)
				options->total = TRUE;
			else
				read_abbreviations(arg, options);
		}
		else
			print_usage();
	}
}

void		read_options(int argc, char *const *argv, t_opt *options)
{
	options->rooms = FALSE;
	options->paths = FALSE;
	options->total = FALSE;
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
