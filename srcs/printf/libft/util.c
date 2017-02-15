#include "ft_printf.h"

char    *ft_strndup_printf(char *s, size_t sz)
{
	char		*d;
	size_t		i;

	i = 0;
	if (!(d = (char *)malloc(sizeof(char) * (sz + 1))))
		return (NULL);
	while (i < sz && s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int     ft_bytes(t_ull b, int i, int bits)
{
    t_ull   sh;

    bits = 0;
    i = 64;
    sh = 1;
    sh = sh << 63;
    while (sh)
    {
        if (sh & b)
            if (bits == 0)
                bits = i;
        sh = sh >> 1;
        i--;
    }
    if (bits <= 8)
        return (1);
    else if (bits <= 16)
        return (2);
    else if (bits <= 32)
        return (4);
    else if (bits <= 64)
        return (8);
    return (16);
}

int     ftwrite(char *s, int l)
{
    write(1, s, l);
    return (l);
}

void    flag__(t_write *wr, int x, char *adr, int max)
{
    if (wr->param->flags['0'])
    {
        wr->cnt += wr->ftwrite("0x", 2);
        while (max + 2 < wr->param->width--)
            wr->cnt += wr->ftwrite("0", 1);
    }
    else
    {
        while (max + 2 < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1); 
        wr->cnt += wr->ftwrite("0x", 2);
    }
    while (wr->param->prec-- > x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(adr, x);
}

void    pointer_address(void *p, t_write *wr)
{
    char    *adr;
    t_ull   ull;
    int     max;
    int     x;

    ull = (t_ull)p;
    adr = ft_utoa_base(ull, 16, 32);
    x = ft_strlen(adr);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (!p && !wr->param->prec && wr->param->flags['.'])
        x = 0;
    if (!wr->param->flags['-'])
        flag__(wr, x, adr, max);
    else
    {
        wr->cnt += wr->ftwrite("0x", 2);
        while (wr->param->prec-- > x)
            wr->cnt += wr->ftwrite("0", 1);
        wr->cnt += wr->ftwrite(adr, x);
        while (max + 2 < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
    }
    free(adr);
}