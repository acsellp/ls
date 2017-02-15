#include <libft.h>

char	*ft_strcpy(char *dest,const char *src)
{
	size_t sz;

	sz = 0;
	while (src[sz])
	{
		dest[sz] = src[sz];
		sz++;
	}
	dest[sz] = '\0';
	return (dest);
}
