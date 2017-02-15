#include "ft_printf.h"

t_ll       ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	return (n * ft_pow(n, p - 1));
}

char        *ft_itoa_base(long long n, int base)
{
	char	*str;
	int		neg;
	int		i;

	neg = 0;
	if (n < 0)
	{
		if (base == 10)
			neg = 1;
		n *= -1;	
	}
	i = 1;
	while (ft_pow(base, i++) - 1 < n);
	str = (char*)malloc(sizeof(char) * (i + neg));
	str[i + neg] = '\x00';
	while (i-- > 0)
	{
		str[i + neg] = (n % base) + (n % base > 9 ? '\x61' - 10 : '\x30');
		n /= base;
	}
	if (neg == 1)
		str[0] = '\x2D';
	return (str);
}

static int  valid (char c)
{
	if (c >= '\x30' && c <= '\x39')
		return (1);
	else if (c >= '\x41' && c <= '\x46')
		return (1);
	else if (c >= '\x61' && c <= '\x66')
		return (1);
	return (0);
}

t_ll       ft_atoi_base(char *s, int base)
{
	t_ll	n;
	int		neg;

	while (*s == '\x0A' || *s == '\x0C' || \
           *s == '\x20' || *s == '\x0D' || *s == '\x0B' || *s == '\x09')
		s++;
	neg = 1;
	if (*s == '\x2D')
		neg = -1;
	if (*s == '\x2D' || *s == '\x2B') 
		s++;
	n = 0;
	while (valid(*s))
	{
		if (*s >= '\x30' && *s <= '\x39')
			n = n * base + *s - '\x30';
		else if (*s >= '\x41' && *s <= '\x46')
			n = n * base + (*s - '\x41' + 10);
		else if (*s >= '\x61' && *s <= '\x66')
			n = n * base + (*s - '\x61' + 10);		
		s++;
	}
	return (n * neg);
}