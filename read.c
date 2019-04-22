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

void		save_line(char *str, t_input *input)
{
	t_glist	*e;

	e = glist_new(str);
	if (input->lines == NULL)
		input->lines = e;
	else
		input->tail->next = e;
	input->tail = e;
	input->line_count += 1;
}

//	return the first non-comment token

void		get_next_token(t_lem *lem, t_token *t)
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
	if (t.type == TOKEN_EOF)	//
		lem_die();				// unexpected end of file
	if (t.type != TOKEN_ANTS)
	{
		lem_die(lem, ERROR_ANTS);
	}
	lem->total_ants = t.value.ants;
}

/*
**	return the room called `name` or NULL if it is not in the list
*/

t_room		*find_room(t_glist *rooms, char const *room_name)
{
	t_room	*r;

	while (rooms != NULL)
	{
		r = rooms->data;
		if (ft_strcmp(r->name, room_name) == 0)
			return (r);
		rooms = rooms->next;
	}
	return (NULL);
}

//	TODO: make sure that ft_strcmp(src_name, dst_name) != 0

void		add_link(t_token *t)
//void		add_link(char const *src_name, char const *dst_name)
{
	t_room	*src;
	t_room	*dst;

	if ((src = find_room(lem->graph->rooms, t->value.link.src)) == NULL)
		lem_die();
	if ((dst = find_room(lem->graph->rooms, t->value.link.dst)) == NULL)
		lem_die();
	if (link_find(src, dst) != NULL)
		lem_die();
	link_push(src, dst, LINK_POSITIVE);
	free(src_name);							//
	free(dst_name);							//
}

void		add_room()
{
	t_room	*r;

	if (find_room(lem->graph->rooms, t->value.room.name) != NULL)
		lem_die();
	r = room_new();
	r->name = t->value.room.name;
	r->x = t->value.room.x;
	r->y = t->value.room.y;
	glist_push(&lem->graph->rooms, glist_new(r));
	if ()
		lem->graph->start = r;
	else if ()
		lem->graph->end = r;
}

int			read_room()		// t_bool
{
	t_token	t;

	get_next_token(lem, &t);
	if (t.type == TOKEN_ROOM)
		add_room();
	else if (t.type == TOKEN_COMMAND_START)
	{
		if (lem->graph->start != NULL)
			lem_die();
		get_next_token(lem, &t);
		if (t.type != TOKEN_ROOM)
			lem_die();
		add_room();
	}
	else if (t.type == TOKEN_COMMAND_END)
	{
		if (lem->graph->end != NULL)
			lem_die();
		get_next_token(lem, &t);		//	repetition:
		if (t.type != TOKEN_ROOM)		//	same
			lem_die();					//	as
		add_room();						//	above
	}
	else
	{

	}
}

void		read_rooms(t_lem *lem, t_token *t)
{
	while (read_room(lem, t))
		;

	t_token	t;

	while (1)
	{
		get_next_token(&t);
		if (t.type == TOKEN_ROOM)
		{
		}
		else if (t.type == TOKEN_COMMAND_START)
		{
		}
		else if (t.type == TOKEN_COMMAND_END)
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
