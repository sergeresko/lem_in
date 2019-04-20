static void	fill_numbers(int n_turns, int i, int n_paths, int const *lengths, int *numbers)
{
	int		j;

	j = 0;
	while (j < i)
	{
		numbers[j] = n_turns - lengths[j];
		++j;
	}
	while (j < n_paths)
	{
		numbers[j] = 0;
		++j;
	}
}

int			distr(int n_ants, int n_paths, int const *lengths, int *numbers)
{
	int		n_turns;
	int		i;
	int		d;

	i = 0;
	while (++i < n_paths)
	{
		d = lengths[i] - lengths[i - 1];
		if (n_ants / i <= d)
			break ;
		n_ants -= d * i;
	}
	d = n_ants / i;
	n_ants -= d * i;
	n_turns = lengths[i - 1] + d;
	fill_numbers(n_turns, i, n_paths, lengths, numbers);
	if (n_ants == 0)
		n_turns -= 1;
	i = 0;
	while (n_ants--)
	{
		numbers[i] += 1;
		++i;
	}
	return (n_turns);
}
