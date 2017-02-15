#include "libft.h"

char *ft_strnstr(const char *b, const char *l, size_t n)
{
	char	*s;
	char	*s1;
	char	*s2;
	size_t	nr;

	if (!*l)
		return ((char*)b);
	s = (char*)b;
	while (*s && n > 0)
	{
		s1 = s;
		s2 = (char*)l;
		nr = n;
		while (!(*s1 - *s2) && *s1 && *s2 && nr > 0)
		{
			s1++;
			s2++;
			nr--;
		}
		if (!*s2)
			return (s);
		s++;
		n--;
	}
	return (NULL);	
}