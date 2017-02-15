
#include "libft.h"

int				ft_tolower(int ch)
{
	if (ft_isupper(ch))
		return (ch - 'A' + 'a');
	return (ch);
}