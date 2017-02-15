#include <libft.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int 	i;
	int				x;

	if (!s || !len)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = start;
	x = 0;
	while (s[i] && (i < start + len))
		str[x++] = s[i++];
	str[x] = '\0';
	return (str);
}
