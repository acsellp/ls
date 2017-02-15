#include <libft.h>

void	*ft_memalloc(size_t size)
{
	unsigned int	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	while (size > 0)
	{
		*p = 0;
		size--;
		p++;
	}
	return (p);
}
