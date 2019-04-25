#ifndef FIND_MORE_PATHS_H
# define FIND_MORE_PATHS_H

# include "datatypes.h"

void		modify_graph(t_room *start, t_room *end);
t_bool		find_shortest_path(t_room *src, t_room *end);
void		restore_graph(t_room *start, t_room *end);
void		xor_paths(t_room *start, t_room *end);

#endif
