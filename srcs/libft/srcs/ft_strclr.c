#include <libft.h>

void	ft_strclr(char *s)
{
	int sz;

	sz = 0;
	while (s[sz])
		sz++;
	while (sz >= 0)
	{
		*s = '\0';
		s++;
		sz--;
	}
}
