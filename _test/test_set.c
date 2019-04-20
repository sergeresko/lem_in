#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lem_in.h"

void	print_room(t_room *r)
{
	if (r == NULL)
		printf("  none\n");
	else
		printf("  Room { name: \"%s\", distance: %d }\n", r->name, r->distance);
}

void	print_set(t_set *s)
{
	t_glist	*e;

	printf("Set [\n");
	e = s->elements;
	while (e != NULL)
	{
		print_room(e->data);
		e = e->next;
	}
	printf("]\n");
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
	a->distance = 42;
	b->distance = 0;
	c->distance = 9000;

	t_set	*s;

	s = set_new();
	print_set(s);

	set_push(s, a);
	set_push(s, a);
	set_push(s, b);
	set_push(s, a);
	set_push(s, b);
	set_push(s, c);
	set_push(s, a);
	set_push(s, b);
	set_push(s, c);
	print_set(s);

	for (int i = 0; i < 7; ++i)
	{
		t_room	*r;
		printf("pop:");
		r = set_pop_min(s);
		if (r == NULL)
			printf("    none\n");
		else
			print_room(r);
		print_set(s);
	}

	set_push(s, c);
	set_push(s, b);
	print_set(s);
	printf("pop:");
	print_room(set_pop_min(s));
	print_set(s);

	set_destroy(&s);

	system("leaks -q a.out");
	return (0);
}
