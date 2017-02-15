

#include "libft.h"

char		*ft_strcpy(char *d, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}