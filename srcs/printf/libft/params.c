#include "ft_printf.h"

void    ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
}

int     ft_flags_wc(t_write *wr, wchar_t c, int len)
{
	if (wr->param->prec)
    {
        ft_putwchar(c);
        while (wr->param->width++ < 1)
            ft_putchar(' ');
        return (wr->param->width);
    }
	else
	{
		if (wr->param->flags['0'])
            while (wr->param->width < len--)
                ft_putchar('0');
		else
            while (wr->param->width < len--)
                ft_putchar(' ');
		ft_putwchar(c);
	}
	return (wr->param->width);
}

char    *ft_strjoindel(char const *s1, char const *s2, int vect)
{
	size_t		i;
	size_t		x;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		str[i++] = s2[x];
		x++;
	}
	str[i] = '\0';
	!vect ? free((void*)s1) : free((void*)s2);
	return (str);
}