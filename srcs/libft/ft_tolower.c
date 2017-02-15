#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65 && c <= 90) && c > 0)
		return (c + 32);
	else if ((c > 0 && c <= 65) || (c > 0 && c >= 90))
		return (c);
	else if (c < 0 && c >= -128 && c < -1)
		return (c + 256);
	return (c);
}
