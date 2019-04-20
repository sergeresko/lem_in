#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lem_in.h"

void	init_graph_2(t_graph *g)
{
	t_room	*start, *a, *b, *c, *d, *e, *f, *end;

	start = room_new();
	start->name = strdup("start");
	a = room_new();
	a->name = strdup("A");
	b = room_new();
	b->name = strdup("B");
	c = room_new();
	c->name = strdup("C");
	d = room_new();
	d->name = strdup("D");
	e = room_new();
	e->name = strdup("E");
	f = room_new();
	f->name = strdup("F");
	end = room_new();
	end->name = strdup("end");

	g->start = start;
	g->end = end;

	glist_push(&g->rooms, glist_new(start));
	glist_push(&g->rooms, glist_new(a));
	glist_push(&g->rooms, glist_new(b));
	glist_push(&g->rooms, glist_new(c));
	glist_push(&g->rooms, glist_new(d));
	glist_push(&g->rooms, glist_new(e));
	glist_push(&g->rooms, glist_new(f));
	glist_push(&g->rooms, glist_new(end));

	link_push(start, a, 1);
	link_push(a, start, 1);
	link_push(a, d, 1);
	link_push(d, a, 1);
	link_push(d, e, 1);
	link_push(e, d, 1);
	link_push(start, b, 1);
	link_push(b, start, 1);
	link_push(b, e, 1);
	link_push(e, b, 1);
	link_push(b, c, 1);
	link_push(c, b, 1);
	link_push(e, end, 1);
	link_push(end, e, 1);
	link_push(c, f, 1);
	link_push(f, c, 1);
	link_push(f, end, 1);
	link_push(end, f, 1);
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

void	print_paths(t_graph *g)
{
	t_glist	*links;
	t_link	*l;
	t_room	*r;

	printf("Paths [\n");
	links = g->start->links;
	while (links != NULL)
	{
		l = links->data;
		r = l->dst;
		if (r->pred == g->start)
		{
			printf("  start");
			while (r != NULL)
			{
				printf(" %s", r->name);
				r = r->succ;
			}
			printf("\n");
		}
		links = links->next;
	}
	printf("]\n");
}

void	print_path(t_room *end)
{
	printf("Path [ ");
	printf("%s", end->name);
	while ((end = end->parent) != NULL)
	{
		printf(" <- %s", end->name);
	}
	printf(" ]\n");
}

int		main(void)
{
	t_graph	g;

	init_graph_2(&g);
	print_graph(&g);

	printf("bhandari: %d\n", bhandari(&g));
	print_paths(&g);
	print_graph(&g);

	t_link	*l = g.end->links->next->data;
	print_room(l->dst);

//	modify_graph(g.start, g.end);
//	print_links(g.end->links);

//	(void)dijkstra(g.start, g.end);
//	print_path(g.end);
//
	printf("bhandari: %d\n", bhandari(&g));
	print_paths(&g);

	print_graph(&g);

	system("leaks -q a.out");

	return (0);
}
