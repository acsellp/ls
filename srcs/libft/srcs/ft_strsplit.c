#include <libft.h>

char **ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		sz;
	int		i;
	int		x;

	sz = ft_strlen(s);
	arr = (char**)malloc(sizeof(char*) * sz);
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		x = 0;
		while (*s != c)
		{
			arr[i][x] = (char)*s;
			x++;
			s++;
			if (*s == c)
			{
				arr[i][x] = '\0';
				i++;
			}
		}
		s++;
	}
	arr[i] = '\0';
	return (arr);
}
