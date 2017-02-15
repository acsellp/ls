#include <libft.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*str;

	l = 0;
	while (s1[l])
		l++;
	while (s2[l])
		l++;
	str = (char*)malloc(sizeof(char) * l);
	while (*s1)
	{
		*str = (char)*s1;
		s1++;
		str++;
	}
	while (*s2)
	{
		*str = (char)*s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (str);
}
