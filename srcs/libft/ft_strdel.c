#include <libft.h>
#include <string.h>

void	ft_strdel(char **as)
{
	int i;

	if (!as || !(*(as)))
		return ;
	i = 0;
	while (*(*(as + i)))
	{
		*(*(as + i)) = '\0';
		i++;
	}
	*as = NULL;	
}
