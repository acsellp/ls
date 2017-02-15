#include <libft.h>

int	ft_atoi(const char *str)
{
	int		res;
	int		s;
	
	res = 0;
	while (*str == ' ' || *str == '\v' || *str == '\t' || *str == '\r' || *str == '\n' || *str == '\f')
		str++;
	s = 1;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * s);
}
