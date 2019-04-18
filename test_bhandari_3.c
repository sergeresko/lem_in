#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lem_in.h"

void	init_graph_3(t_graph *g)
{
	t_room	*start, *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10,
			*r11, *r12, *r13, *r14, *r15, *r16, *r17, *end;

	start = room_new();
	start->name = strdup("start");
	r1 = room_new();
	r1->name = strdup("1");
	r2 = room_new();
	r2->name = strdup("2");
	r3 = room_new();
	r3->name = strdup("3");
	r4 = room_new();
	r4->name = strdup("4");
	r5 = room_new();
	r5->name = strdup("5");
	r6 = room_new();
	r6->name = strdup("6");
	r7 = room_new();
	r7->name = strdup("7");
	r8 = room_new();
	r8->name = strdup("8");
	r9 = room_new();
	r9->name = strdup("9");
	r10 = room_new();
	r10->name = strdup("10");
	r11 = room_new();
	r11->name = strdup("11");
	r12 = room_new();
	r12->name = strdup("12");
	r13 = room_new();
	r13->name = strdup("13");
	r14 = room_new();
	r14->name = strdup("14");
	r15 = room_new();
	r15->name = strdup("15");
	r16 = room_new();
	r16->name = strdup("16");
	r17 = room_new();
	r17->name = strdup("17");
	end = room_new();
	end->name = strdup("end");

	g->start = start;
	g->end = end;

	glist_push(&g->rooms, glist_new(start));
	glist_push(&g->rooms, glist_new(r1));
	glist_push(&g->rooms, glist_new(r2));
	glist_push(&g->rooms, glist_new(r3));
	glist_push(&g->rooms, glist_new(r4));
	glist_push(&g->rooms, glist_new(r5));
	glist_push(&g->rooms, glist_new(r6));
	glist_push(&g->rooms, glist_new(r7));
	glist_push(&g->rooms, glist_new(r8));
	glist_push(&g->rooms, glist_new(r9));
	glist_push(&g->rooms, glist_new(r10));
	glist_push(&g->rooms, glist_new(r11));
	glist_push(&g->rooms, glist_new(r12));
	glist_push(&g->rooms, glist_new(r13));
	glist_push(&g->rooms, glist_new(r14));
	glist_push(&g->rooms, glist_new(r15));
	glist_push(&g->rooms, glist_new(r16));
	glist_push(&g->rooms, glist_new(r17));
	glist_push(&g->rooms, glist_new(end));

	link_push(start, r1, 1);	link_push(r1, start, 1);
	link_push(r1, r2, 1);		link_push(r2, r1, 1);
	link_push(r2, r3, 1);		link_push(r3, r2, 1);
	link_push(r3, r4, 1);		link_push(r4, r3, 1);
	link_push(r4, r5, 1);		link_push(r5, r4, 1);
	link_push(r5, end, 1);		link_push(end, r5, 1);
	link_push(start, r6, 1);	link_push(r6, start, 1);
	link_push(r6, r16, 1);		link_push(r16, r6, 1);
	link_push(r16, r17, 1);		link_push(r17, r16, 1);
	link_push(r17, r5, 1);		link_push(r5, r17, 1);
	link_push(r6, r7, 1);		link_push(r7, r6, 1);
	link_push(r7, r8, 1);		link_push(r8, r7, 1);
	link_push(r8, r5, 1);		link_push(r5, r8, 1);
	link_push(r8, r9, 1);		link_push(r9, r8, 1);
	link_push(r9, r10, 1);		link_push(r10, r9, 1);
	link_push(r10, end, 1);		link_push(end, r10, 1);
	link_push(start, r11, 1);	link_push(r11, start, 1);
	link_push(r11, r8, 1);		link_push(r8, r11, 1);
	link_push(r11, r12, 1);		link_push(r12, r11, 1);
	link_push(r12, r13, 1);		link_push(r13, r12, 1);
	link_push(r13, r14, 1);		link_push(r14, r13, 1);
	link_push(r14, r15, 1);		link_push(r15, r14, 1);
	link_push(r15, end, 1);		link_push(end, r15, 1);
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

	init_graph_3(&g);
	print_graph(&g);

	printf("bhandari: %d\n", bhandari(&g));
	print_paths(&g);
	print_graph(&g);

	printf("bhandari: %d\n", bhandari(&g));
	print_paths(&g);
	print_graph(&g);

	printf("bhandari: %d\n", bhandari(&g));
	print_paths(&g);
	print_graph(&g);

	printf("bhandari: %d\n", bhandari(&g));

	system("leaks -q a.out");

	return (0);
}
