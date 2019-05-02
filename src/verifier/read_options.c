#include <unistd.h>
#include "libft.h"
#include "lem_in.h"
#include "error.h"

static void		print_usage(void)
{
	ft_putstr_fd("usage: ./verifier [options] < lem_in_output\n\n"
			"See `./verifier --help` for more information.\n",
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
	options->input = FALSE;
	if (argc > 1)
		read_arguments(argv, options);
}
