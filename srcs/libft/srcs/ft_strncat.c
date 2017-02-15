#include <libft.h>

char *ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	sz;
	size_t	i;

	sz = 0;
	while (dest[sz])
		sz++;
	i = 0;
	while (i < n && src[i])
	{
		dest[sz + i] = src[i];
		i++;
	}
	dest[sz + i] = '\0';
	return (dest);
}
