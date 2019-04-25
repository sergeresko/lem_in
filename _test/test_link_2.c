#include <string.h>		// strdup
#include <stdlib.h>		// system
#include <stdio.h>
#include "lem_in.h"

#define DEBUG_PTR(ptr) ((unsigned)(((unsigned long long)(ptr) & 0xfffff0) >> 4))

void	print_links(t_room *src)
{
	t_glist	*links;
	t_link	*l;

	printf("Links from %s:\n", src->name);
	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		printf("    %05x [ link: %05x (%s -> %s, %d), next: %05x ]\n",
				DEBUG_PTR(links), DEBUG_PTR(l), src->name, l->dst->name, l->weight, DEBUG_PTR(links->next));
		links = links->next;
	}
}

int		main(void)
{
	t_room	*a, *b, *c, *d, *e;

	a = room_new();
	b = room_new();
	c = room_new();
	d = room_new();
	e = room_new();
	a->name = strdup("A");
	b->name = strdup("B");
	c->name = strdup("C");
	d->name = strdup("D");
	e->name = strdup("E");

	print_links(a);
	print_links(b);
	print_links(c);
	print_links(d);
	print_links(e);
	printf("\n");

	link_push(a, b, 1);
	print_links(a);
	printf("\n");

	link_delete(a, b);
	print_links(a);
	printf("\n");

	link_push(a, b, 1);
	link_push(a, c, 1);
	print_links(a);
	printf("\n");

	link_delete(a, b);
	print_links(a);
	printf("\n");

	link_push(a, d, 1);
	print_links(a);
	printf("\n");

	link_delete(a, d);
	print_links(a);
	printf("\n");

	/*	
	link_push(a, b, 1);
	printf("%s\n", ((t_link *)a->links->data)->dst->name);
	link_push(a, c, 1);
	printf("%s\n", ((t_link *)a->links->data)->dst->name);

	t_room	*r = link_pop(a);
	printf("%s\n", r->name);
	printf("%s\n", ((t_link *)a->links->data)->dst->name);

	link_delete(a, b);
	printf("%p\n", a->links);

	link_push(b, a, 0);
	link_push(b, c, 0);
	link_push(b, b, 0);
	link_push(b, b, 0);
	print_links(b);
	link_delete(b, a);
	print_links(b);

	system("leaks -q a.out");
	*/

	return (0);
}
