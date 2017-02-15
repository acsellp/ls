#include <libft.h>

size_t	ft_strlen(const char *str)
{
	size_t sz;

	sz = 0;
	while (str[sz] != '\0')
		sz++;
	return (sz);
}
