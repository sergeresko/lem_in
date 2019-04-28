// <
//
#include <stdlib.h>		// system
//
// > 
#include "lem_in.h"

int			main(int argc, char **argv)
{
	t_lem	lem;

	// process options
	read_options(argc, argv, &lem.options);
	// TODO: help
	/*
	if (lem.options.help)
	{
		print_help();
		return (0);
	}
	*/
	// process input
	read_input_verifier(&lem);
	// print answer
	// <
	//
	system("leaks -q verifier");
	//
	// >
	return (0);
}
