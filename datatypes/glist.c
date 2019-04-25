/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:34:26 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/17 20:15:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// {
#ifdef DEBUG
# include "libft.h"		// for debugging
#endif
// }
#include <stdlib.h>		// malloc, free, NULL
#include "datatypes.h"
// {
#ifdef DEBUG
# define DEBUG_PTR(ptr) (((unsigned long long)(ptr) & 0xfffff0) >> 4)
#endif
// }

/*
**	allocate a new element initialized with `data`
*/

t_glist		*glist_new(void *data)
{
	t_glist	*elem;

	elem = malloc(sizeof(t_glist));
// {
#ifdef DEBUG
	ft_printf(PF_YELLOW"[malloc %05x (glist)]"PF_RESET, DEBUG_PTR(elem));
#endif
// }
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

/*
**	prepend an element to the list whose first element's address is `head`
*/

void		glist_push(t_glist **head, t_glist *elem)
{
	elem->next = *head;
	*head = elem;
}

/*
**	delete one element from a list
**
**	If the element is the first one in the list, call the function like this:
**		glist_delete(&head);
**	If the element follows element `p` in the list, call it like this:
**		glist_delete(&p->next);
*/

void		glist_delete(t_glist **elem)
{
	t_glist	*del;

	del = *elem;
	*elem = del->next;
	free(del);
// {
#ifdef DEBUG
	ft_printf(PF_YELLOW"[free %05x (glist)]"PF_RESET, DEBUG_PTR(del));
#endif
// }
}
