

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char	*ret;

	ret = ft_strchr(s1, '\0');
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (s1);
}