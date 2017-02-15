#include <libft.h>
#include <stdlib.h>

static int	size(int nr)
{
	int i;

	i = 1;
	if (nr > 0)
	{
		while (nr > 10)
		{
			nr /= 10;
			i++;
		}
	}
	else
	{
		while (nr < -10)
		{
			nr /= 10;
			i++;
		}
	}
	return (i);
}

static char *revers(char *str, int n)
{
	char	r[20];
	int		nr;

	if (n < 1)
		return (str);
	nr = 0;
	while (nr <= n)
	{
		r[nr] = str[n - nr];
		nr++;
	}
	r[nr] = '\0';
	ft_strcpy(str, r);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int 	sz;
	int 	neg;
	int		i;

	sz = size(n);
	neg = 1;
	if (n < 0)
		neg = -1;
	str = (char*)malloc(sizeof(char) * sz + 1);
	i = 0;
	while (i < sz)
	{
		str[i] = ((n % 10) * neg) + 48;
		n /= 10;
		i++;
	}
	if (neg == -1)
		str[i++] = '-';
	revers(str, i - 1);
	return (str);
}
