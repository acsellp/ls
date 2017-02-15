#include <libft.h>

static int	size(int nr)
{
	int i;

	i = 1;
	while (nr > 10)
	{
		nr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int 	sz;

	sz = size(n);	
	str = (char*)malloc(sizeof(char) * sz + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		str++;
		n *= -1;
	}
	while (n > 0)
	{
		*str = n % 10;
		n /= 10;
		str++;
	}
	*str = '\0';
	return (str);
}
