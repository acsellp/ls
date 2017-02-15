#include <libft.h>

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1024);
	return (0);
}
