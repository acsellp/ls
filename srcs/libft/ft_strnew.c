#include <libft.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		*str = 0;
		str++;
		size--;
	}
	*str = '\0';
	return (str);
}
