/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:21:48 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/24 11:29:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	t_lem		lem;
	t_solution	solution;

	read_options(argc, argv, &lem.options);
	if (lem.options.help)
		print_help();

	read_input(&lem);
	if (lem.options.input)
		print_input(lem);
	if (lem.options.rooms)
		print_rooms(lem);

	if (lem.total_ants > 0)
	{
		if (find_link(lem.graph->start, lem.graph->end))
			print_trivial_solution(lem);
		else
		{
			solve(lem, &solution);
			print_solution(lem, &solution);
		}
	}
	return (0);
}
