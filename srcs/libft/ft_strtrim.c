#include <libft.h>
#include <stdlib.h>
#include <string.h>

char *ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	f;
	size_t	n;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i + 1])
		i++;
	while (i)
		if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		else
			break;
	f = 0;
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f++;
	str = (char*)malloc(sizeof(char) * 100);
	if (!str)
		return (NULL);
	n = 0;
	while (f <= i)
		str[n++] = s[f++];
	str[n] = '\0';
	return (str);
}
