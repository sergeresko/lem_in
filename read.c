void	read_ants(void)
{
	char	*str;
	t_token	t;

	while (get_next_line(STDIN_FILENO, &str) == GNL_OK)
	{
		t = parse(str);
		if (t.type == COMMENT)
	}
}

void	read_rooms()
{
}

void	read_links()
{
}
