#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int 	i;

	str = (char*)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	while (*s && (start < i) && len > 0)
	{
		*str = *s;
		str++;
		s++;
		start++;
		len--;
	}
	*str = '\0';
	return (str);
}
