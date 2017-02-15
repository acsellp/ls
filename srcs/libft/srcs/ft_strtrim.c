#include <libft.h>

char *ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		f;

	i = 0;
	while (s[i])
		i++;
	while (s[i] == ' ' && s[i] == '\n' && s[i] == '\t')
		i--;
	f = 0;
	while (s[i] == ' ' && s[i] == '\n' && s[i] == '\t')
		f++;
	str = (char*)malloc(sizeof(char) * i - f + 1);
	if (!str)
		return (NULL);
	while (f < i)
	{
		*str = s[f];
		f++;
		str++;
	}
	*str = '\0';
	return (str);
}
