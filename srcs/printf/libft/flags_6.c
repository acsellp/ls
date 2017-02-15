#include "ft_printf.h" 

void    ft_prec_width_wstr(char *str, t_write *wr)
{
	if (wr->param->flags['.'])
	{
		if ((wr->param->width == 0) || \
            (wr->param->prec < wr->param->width && wr->param->prec > 1))
			str = ft_strndup_printf(str, wr->param->prec - 1);
		if ((wr->param->width > 0) || (wr->param->width > 0 && \
                                       wr->param->prec == 1))
			str = ft_strndup_printf(str, wr->param->prec);
	}
	if (wr->param->flags['-'])
	{
		wr->cnt += ftwrite(str, ft_strlen(str));
		while ((int)ft_strlen(str) < wr->param->width--)
			wr->cnt += ftwrite(wr->param->flags['0'] ? "0" : " ", 1);
	}
	else
	{
		while ((int)ft_strlen(str) < wr->param->width--)
			wr->cnt += ftwrite(wr->param->flags['0'] ? "0" : " ", 1);
		wr->cnt += ftwrite(str, ft_strlen(str));
	}
}

void    wchar_char(wchar_t c, int i, char *ret)
{
	if (c <= 0x7F)
		ret[i++] = (char)c;
	else if (c <= 0x7FF)
    {
        ret[i++] = (char)((c >> 6) | 0xC0);
		ret[i++] = (char)((c & 0x3F) | 0x80);
    }
	else if (c <= 0xFFFF)
	{
        ret[i++] = (char)((c >> 12) | 0xE0);
		ret[i++] = (char)(((c >> 6) & 0x3F) | 0x80);
		ret[i++] = (char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
        ret[i++] = (char)((c >> 18) | 0xF0);
		ret[i++] = (char)(((c >> 12) & 0x3F) | 0x80);
		ret[i++] = (char)(((c >> 6) & 0x3F) | 0x80);
		ret[i++] = (char)((c & 0x3F) | 0x80);
	}
    ret[i] = '\0';
}

char    *wstr_to_str(wchar_t *s)
{
	int			i;
	char		*tmp;
	char		*str;

	i = ft_wstrlen(s);
	str = (char*)malloc(sizeof(char) * (i + 1));
    tmp = (char*)malloc(sizeof(char) * 5);
    i = 0;
	while (s[i])
	{
		wchar_char(*(s + i), 0, tmp);
        ft_strcat(str, tmp);
        if (s[i] == L'\0')
            free(tmp);
        i++;
	}
	free(tmp);
	return (str);
}


int     wcharlen(wchar_t c)
{
    if (c <= 0x7F)
        return (1);
    else if (c <= 0x7FF)
        return (2);
    else if (c <= 0xFFFF)
        return (3);
    else if (c <= 0x10FFFF)
        return (4);
    return (0);
}

int     ft_wstrlen(wchar_t *ws)
{
    int ret;
    int i;
    
    ret = 0;
    i = 0;
    while (ws[i])
    {
        ret += wcharlen(ws[i]);
        i++;
    }
    return (ret);
}