
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char	*n;

	n = malloc(ft_strlen(s1) + 1);
	if (n == NULL)
		return (NULL);
	ft_strcpy(n, s1);
	return (n);
}