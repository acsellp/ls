
#include "libft.h"

char		*ft_strncat(char *f, const char *s, size_t sz)
{
	char	*str;
	size_t	i;

	str = ft_strchr(f, '\0');
	i = 0;
	while (s[i] && i < sz)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (f);
}