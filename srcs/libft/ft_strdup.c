#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size;
	char	*str;
	int		i;

	size = 0;
	while (s[size])
		size++;
	i = 0;
	str = (char*)malloc(sizeof(char) * size);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
