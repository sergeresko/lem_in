#include <stdlib.h>
#include <stdio.h>

void		*ft_malloc_or_die(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
	{
		perror("malloc");
		exit(1);
	}
	return (ptr);
}
