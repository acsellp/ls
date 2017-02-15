#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int sz;

	if (!s)
		return (NULL);
	sz = 0;
	while (s[sz])
		sz++;
	while (sz > 0)
	{
		if (*(s + sz) == c)
			return ((char*)(s + sz));
		sz--;
	}
	return (NULL);
}
