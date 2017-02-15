#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	if (!c)
		return (str + i);
	i--;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (NULL);
}
