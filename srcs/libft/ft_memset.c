#include <libft.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
	size_t			nr;
	unsigned char	*p;

	p = (unsigned char*)s;
	nr = 0;
	while (nr < n)
	{
		*p = c;
		nr++;
		p++;
	}
	return (s);
}
