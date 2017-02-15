#include <libft.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(p + i) = 0;
		i++;
	}
	return ((void*)p);
}
