#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lem_in.h"

t_path	**init(void)
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

	r1->succ = r2;
	r2->succ = r3;
	r3->succ = r4;
	r4->succ = r5;
	r5->succ = end;
	r6->succ = r7;
	r7->succ = r8;
	r8->succ = r9;
	r9->succ = r10;
	r10->succ = end;
	r11->succ = r12;
	r12->succ = r13;
	r13->succ = r14;
	r14->succ = r15;
	r15->succ = end;

	t_path	**paths = malloc(3 * sizeof(t_path *));

	paths[0] = malloc(sizeof(t_path));
	paths[0]->origin = r1;
	paths[0]->length = 5;
	paths[0]->ants = 4;

	paths[1] = malloc(sizeof(t_path));
	paths[1]->origin = r1;
	paths[1]->length = 5;
	paths[1]->ants = 4;

	paths[2] = malloc(sizeof(t_path));
	paths[2]->origin = r1;
	paths[2]->length = 5;
	paths[2]->ants = 4;

	return (paths);
}

int		main(void)
{
	t_path	**paths;

	paths = init();

	print_solution(paths, 3, 12);

	return (0);
}
