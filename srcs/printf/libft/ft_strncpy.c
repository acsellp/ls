

#include "libft.h"

char		*ft_strncpy(char *d, const char *s, size_t max)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < max)
	{
		d[i] = s[i];
		i++;
	}
	while (i < max)
	{
		d[i] = '\0';
		i++;
	}
	return (d);
}