typedef struct s_input	t_input;
typedef struct s_lem	t_lem;

struct		s_input
{
	int		line_count;
	t_glist	*lines;
	t_glist	*tail;
};

struct		s_lem
{
	t_input	*input;
	int		total_ants;
	t_graph	*graph;
};

void		get_next_token(t_token *t)
{
	int		status;
	char	*str;

	while ((status = get_next_line(STDIN_FILENO, &str)) == GNL_OK)
	{
		save_line(str, lem->input);
		parse(str, t);
		if (t->type != TOKEN_COMMENT)
			return ;
	}
	if (status == GNL_EOF)
	{
		t->type = TOKEN_EOF;
		return ;
	}
	if (status == GNL_ERROR)
	{
		// TODO:
	}
}

void		read_ants(t_lem *lem)
{
	t_token	t;

	get_next_token(lem->input, &t);
	if (t.type != TOKEN_ANTS)
	{
		lem_die(lem, ERROR_ANTS);
	}
	lem->total_ants = t.value.ants;
}

void		read_rooms(t_lem *lem)
{
	t_token	t;

	while (1)
	{
		get_next_token(&t);
		if (t.type == TOKEN_ROOM)
		{
		}
		else if (t.type == TOKEN_START)
		{
		}
		else if (t.type == TOKEN_END)
		{
		}
		else if (t.type == TOKEN_LINK)
		{
		}
		else
		{
		}
	}
}

void		read_links()
{
}
