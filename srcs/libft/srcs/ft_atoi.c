#include <libft.h>

int	ft_atoi(const char *str)
{
	int nr;
	int	s;

	nr = 0;
	s = 1;
	while (*str == '\n' || *str == '\r' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nr = (nr * 10) + (*str - '0');
		str++;
	}
	return (nr * s);
}
