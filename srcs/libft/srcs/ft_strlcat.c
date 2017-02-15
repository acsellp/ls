#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	id;
	size_t	is;

	id = 0;
	while (dest[id])
		id++;
	is = 0;
	while (src[is])
		is++;
	if (n < id)
		return (n + is);
	while (*src && id < n - 1)
	{
		dest[id] = *src;
		id++;
		src++;
	}
	dest[id] = '\0';
	return (id + is);
}
