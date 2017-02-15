
#include "libft.h"

int     ft_isdigit(int c)
{
	return (c <= '\x39' && c >= '\x30');
}