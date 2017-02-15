
#include "libft.h"

void			*ft_memset(void *d, int n, size_t len)
{
	size_t			i;
	unsigned char	*loc;
	unsigned char	val;

	val = (unsigned char)n;
	loc = (unsigned char*)d;
	i = 0;
	while (i < len)
	{
		loc[i] = val;
		i++;
	}
	return (d);
}