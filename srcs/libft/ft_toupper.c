#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97 && c <= 122) && c > 0)
		return (c - 32);
	else if ((c > 0 && c <= 97) || (c > 0 && c >= 122))
		return (c);
	else if (c < 0 && c >= -128 && c < -1)
		return (c + 256);
	return (c);
}
