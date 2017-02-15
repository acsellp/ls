#include <libft.h>

char	*ft_strstr(const char *h, const char *n)
{
	char	*s;
	char	*st;
	char	*ss;

	if (!*n)
		return ((char*)h);
	s = (char*)h;
	while (*s)
	{
		st = s;
		ss = (char*)n;
		while (!(*st - *ss) && *st && *ss)
		{
			st++;
			ss++;
		}
		if (!*ss)
			return (s);
		s++;
	}
	return (NULL);
}
