#include "ft_printf.h"

void    format_string_s(va_list ap, t_write *wr)
{
    char    *s;
    int     x;
    int     min;

    if (wr->param->lenght == 'l')
	{
		format_string_w(ap, wr);
        return ;
	}
    s = (char *)va_arg(ap, char *);
    if (!s && !wr->param->flags['.'] && (wr->cnt += wr->ftwrite("(null)", 6)))
        return ;
    x = ft_strlen(s);
    if (wr->param->flags['.'])
        min = (wr->param->prec < x) ? wr->param->prec : x;
    else
        min = x;
    if (wr->param->flags['.'])
        flag30s(s, wr, &x, &min);
    else if (wr->param->flags['-'])
        flag2Ds(s, wr, &x, &min);
    else
        flag20s(s, wr, &x, &min);
}

void    format_string_w(va_list ap, t_write *wr)
{
	wchar_t		*wstr;
	char		*p;

	if (!(wstr = (wchar_t*)va_arg(ap, wchar_t*)))
		wr->cnt += wr->ftwrite("(null)", 6);
	else
	{
        p = ft_strdup("");
        free(p);
		p = wstr_to_str(wstr);
		ft_prec_width_wstr(p, wr);
		free(p);
	}
}

void    format_char_w(va_list ap,  t_write *wr)
{
    int             x;
    wchar_t         chr;
    
    x = 0;
    chr = (wchar_t)va_arg(ap, wint_t);
    if (chr <= 0x7F)
		x += 1;
	else if (chr <= 0x7FF)
		x += 2;
	else if (chr <= 0xFFFF)
		x += 3;
	else if (chr <= 0x10FFFF)
		x += 4;
    if (wr->param->width > x)
    {
        wr->cnt += ft_flags_wc(wr, chr, x);
        return ;
    }
    wr->cnt += x;
    ft_putwchar(chr);
}

void    char_flags(t_write *wr, char c)
{
	if (wr->param->flags['-'])
	{
		wr->cnt += ftwrite(&c, 1);
		while (0 < --wr->param->width)
			wr->cnt += wr->ftwrite(" ", 1);
	}
	else
	{
		if (wr->param->flags['0'])
			while (0 < --wr->param->width)
				wr->cnt += wr->ftwrite("0", 1);
		else
			while (0 < --wr->param->width)
				wr->cnt += wr->ftwrite(" ", 1);
		wr->cnt += ftwrite(&c, 1);
	}
}

void    format_char_c(va_list ap,  t_write *wr)
{
    unsigned char   c; 

    if (wr->param->lenght == 'l')
    {
        format_char_w(ap, wr);
        return ;
    }
    else
        c = va_arg(ap, int);
    if (wr->param->width > 1)
    {
		char_flags(wr, (char)c);
		return ;
    }
    wr->cnt += ftwrite((char*)&c, 1);
}