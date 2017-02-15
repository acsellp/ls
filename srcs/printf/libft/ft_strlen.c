
#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t	sz;

	if (s == NULL)
		return (0);
	sz = 0;
	while (s[sz])
		sz++;
	return (sz);
}