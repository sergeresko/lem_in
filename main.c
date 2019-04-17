#include <string.h>		// strdup
#include <unistd.h>		// sleep
#include <stdio.h>
#include "lem_in.h"

void	print_links(t_room *src)
{
	t_glist	*links;
	t_link	*l;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		printf("\"%s\"->\"%s\" (%d)\n", src->name, l->dst->name, l->weight);
		links = links->next;
	}
}

int		main(void)
{
	t_room	*a, *b, *c;

	a = room_new();
	b = room_new();
	c = room_new();
	a->name = strdup("room a");
	b->name = strdup("room b");
	c->name = strdup("room c");
	
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

	sleep(30);
	return (0);
}
