#include "lem_in.h"
#include "parse.h"

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

// ----------------------------------------------------------------------------

static void	save_line(char *str, t_input *input)
{
	t_glist	*item;

	item = glist_new(str);
	if (input->lines == NULL)
		input->lines = item;
	else
		input->tail->next = item;
	input->tail = item;
	input->line_count += 1;
}

/*
**	read and save lines until first non-comment or end of file,
**	construct a respective token
*/

void		get_next_token(t_lem *lem, t_token *token)
{
	int		status;
	char	*str;

	while ((status = get_next_line(STDIN_FILENO, &str)) == GNL_OK)
	{
		save_line(str, lem->input);
		tokenize(str, token);
		if (token->type != TOKEN_COMMENT)
			return ;
	}
	if (status == GNL_EOF)
	{
		token->type = TOKEN_EOF;
		return ;
	}
	if (status == GNL_ERROR)
	{
		// TODO: ... exit(1)
	}
}

// ----------------------------------------------------------------------------

void		read_ants(t_lem *lem, t_token *token)
{
	get_next_token(lem->input, token);
	if (token->type == TOKEN_EOF)
		lem_die(lem, "unexpected end of file");		///////////////
	if (token->type != TOKEN_ANTS)
//	{
		lem_die(lem, "invalid number of ants (a non-negative integer expected)");
//	}
	lem->total_ants = token->value.ants;
}

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

#define ROOM_STANDARD	0
#define ROOM_START		1
#define ROOM_END		2

static void	add_room(t_lem *lem, t_token *token)
{
	t_room	*room;

	if (find_room(lem->graph->rooms, token->value.room.name) != NULL)
		lem_die(lem, "already has a room with this name");
	room = room_new();
	room->name = token->value.room.name;
	room->x = token->value.room.x;
	room->y = token->value.room.y;
	glist_push(&lem->graph->rooms, glist_new(room));
}
/*
static void	read_complex_room(t_lem *lem, t_token *token)
{
	int		room_type;

	room_type = (token->type == TOKEN_COMMAND_START) ? ROOM_START : ROOM_END;
	if (room_type == ROOM_START && lem->graph->start != NULL)
		lem_die(lem, "already has a start");
	if (room_type == ROOM_END && lem->graph->end != NULL)
		lem_die(lem, "already has an end");
	get_next_token(lem, token);
	if (token->type == TOKEN_EOF)
		lem_die(lem, "unexpected end of file");		//////////////
	if (token->type != TOKEN_ROOM)
		lem_die(lem, "invalid room (format: name coord_x coord_y)");
	add_room(lem, token);
	if (room_type == ROOM_START)
		lem->graph->start = lem->graph->rooms->data;
	else if (room_type == ROOM_END)
		lem->graph->end = lem->graph->rooms->data;
}
*/
/*
**	If no error occurred and the function returned FALSE, the final value
**	of `token->type` is one of the following:
**	TOKEN_TURN, TOKEN_LINK, TOKEN_ANTS, TOKEN_EMPTY_LINE, TOKEN_ERROR, TOKEN_EOF.
*/

static int	read_room(t_lem *lem, t_token *token)		// t_bool
{
	get_next_token(lem, token);
	if (token->type == TOKEN_ROOM)
		add_room(lem, token, ROOM_STANDARD);
	else if (token->type == TOKEN_COMMAND_START)
	{
		if (lem->graph->start != NULL)
			lem_die(lem, token, "already has a start");
		get_next_token(lem, token);
		if (token->type != TOKEN_ROOM)
			lem_die(lem, token, "invalid room (format: name coord_x coord_y)");
		add_room(lem, token, ROOM_START);
	}
	else if (token->type == TOKEN_COMMAND_END)
	{
		if (lem->graph->end != NULL)
			lem_die(lem, token, "already has an end");
		get_next_token(lem, token);
		if (token->type != TOKEN_ROOM)
			lem_die(lem, token, "invalid room (format: name coord_x coord_y)");
		add_room(lem, token, ROOM_END);
	}
	return (token->type == TOKEN_ROOM);
}

void		read_rooms(t_lem *lem, t_token *t)
{
	while (read_room(lem, t))
		;
}

// ----------------------------------------------------------------------------

//	TODO: make sure that ft_strcmp(src_name, dst_name) != 0

void		add_link(t_lem *lem, t_token *token)
//void		add_link(char const *src_name, char const *dst_name)
{
	t_room	*src;
	t_room	*dst;

	if ((src = find_room(lem->graph->rooms, token->value.link.src)) == NULL)
		lem_die(lem, token, "has no room called `src`");
	if ((dst = find_room(lem->graph->rooms, token->value.link.dst)) == NULL)
		lem_die(lem, token, "has no room called `dst`");
	if (link_find(src, dst) != NULL)
		lem_die(lem, token, "already has a link between these rooms");
	link_push(src, dst, LINK_POSITIVE);
	link_push(dst, src, LINK_POSITIVE);
	free(src_name);							//
	free(dst_name);							//
}

int			read_link(t_lem *lem, t_token *token)		// t_bool
{
	get_next_token(lem, token);
	if (token->type == TOKEN_LINK)
	{
		if (ft_strcmp(token->value.link.dst, token->value.link.src) == 0)
			lem_die(lem, token, "a room cannot be linked to itself");
		add_link(lem, token);
	}
	return (token->type == TOKEN_LINK);
}

void		read_links()
{
	if (token->type != TOKEN_LINK)
	{
	}

}

void		read()
{
	t_token	token;

	read_ants(lem);
	while (read_room(lem, &token))
		;
	if (token.type != TOKEN_LINK)
		lem_die();		// invalid room or link
	while (read_link(lem, &token))
		;
	if (token.type == TOKEN_EOF)
		lem_die();
	if (token.type != TOKEN_LINK)
		lem_die();
	if (lem->graph->rooms == NULL)
		lem_die();
	if (lem->graph->start == NULL)
		lem_die();
	if (lem->graph->end == NULL)
		lem_die();
}