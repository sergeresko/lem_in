#include <stdlib.h>		// malloc, NULL
#include <stdio.h>
#include "lem_in.h"
#include "parse.h"

void	lem_init(t_lem *lem)
{
	lem->total_ants = 0;		//////////
	lem->input = malloc(sizeof(t_input));
	lem->input->line_count = 0;
	lem->input->lines = NULL;
	lem->input->tail = NULL;
	lem->graph = malloc(sizeof(t_graph));
	lem->graph->rooms = NULL;
	lem->graph->start = NULL;
	lem->graph->end = NULL;
}

void	print_input(t_input *input)
{
	t_glist	*lines;

	lines = input->lines;
	while (lines != NULL)
	{
		printf("%s\n", lines->data);
		lines = lines->next;
	}
}

void	print_links(t_glist *links)
{
	t_link	*l;

	printf("[");
	while (links != NULL)
	{
		l = links->data;
		printf(" %s:%d", l->dst->name, l->weight);
		links = links->next;
	}
	printf(" ]");
}

void	print_room(t_room *r)
{
	if (r == NULL)
		printf("  none\n");
	else
	{
		printf("  Room: { name: \"%s\", distance: %d, links: ",
														r->name, r->distance);
		print_links(r->links);
		printf(" }\n");
	}
}

void	print_graph(t_graph *g)
{
	t_glist	*e;
	t_room	*r;

	printf("Graph [\n");
	e = g->rooms;
	while (e != NULL)
	{
		r = e->data;
		print_room(r);
		e = e->next;
	}
	printf("]\n");
}

int		main(void)
{
	t_lem	lem;

	lem_init(&lem);
	read_input(&lem);
	print_input(lem.input);
	print_graph(lem.graph);

	system("leaks -q a.out");

	return (0);
}
