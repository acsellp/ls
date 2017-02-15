

#include "libft.h"

char			*ft_strchr(const char *s1, int ch)
{
	while (*s1 && *s1 ^ ch)
		s1++;
	if (*s1 == ch)
		return ((char*)s1);
	return (NULL);
}