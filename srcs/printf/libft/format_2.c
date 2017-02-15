#include "ft_printf.h"

void    format_float(va_list ap, t_write *wr)
{
    char    *s;
    int     x;   
    double  f;

    f = va_arg(ap, double);
	s = ft_utoa_base((t_ll)f, 10, 0);
    ft_strcat(s, ".");
    ft_strcat(s, ft_utoa_base(((f - (int)f) * 1000000) + 1, 10, 0));
    x = ft_strlen(s);
    wr->cnt += ftwrite(s, x);
    free(s);
}

void    format_hex_x(va_list ap, t_write *wr)
{
    char    *s;
    int     x;
    int     max;
    t_ull   ull;
    
    if (wr->param->lenght && wr->type[wr->param->lenght](&ull, ap, 1, NULL))
        s = ft_utoa_base(ull, 16, 32);
    else
        s = ft_utoa_base(va_arg(ap, unsigned int), 16, 32);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['#'] && *s != '0')
        max = max + 2;
    if (wr->param->flags['-'])
        flag2Dx(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30x(s, wr, &x, &max);
    else
        flag20x(s, wr, &x, &max);
    free(s);
}

void    format_hex_X(va_list ap, t_write *wr)
{
    char    *s;
    int     x;
    int     max;
    t_ull   ull;
    
    if (wr->param->lenght && wr->type[wr->param->lenght](&ull, ap, 1, NULL))
        s = ft_utoa_base(ull, 16, 0);
    else
        s = ft_utoa_base(va_arg(ap, unsigned int), 16, 0);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['#'] && *s != '0')
        max = max + 2;
    if (wr->param->flags['-'])
        flag2DX(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30X(s, wr, &x, &max);
    else
        flag20X(s, wr, &x, &max);
    free(s);
}

void    format_oct_O(va_list ap,  t_write *wr)
{
    char    *s;
    int     x;
    int     max;
    t_ull   ull;
    
    if (wr->param->lenght && wr->type[wr->param->lenght](&ull, ap, 2, NULL))
        s = ft_utoa_base(ull, 8, 0);
    else
        s = ft_utoa_base((t_ull)va_arg(ap, long int), 8, 0);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['#'] && *s != '0')
        max = max + 1;
    if (wr->param->flags['-'])
        flag2Do(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30o(s, wr, &x, &max);
    else
        flag20o(s, wr, &x, &max);
    free(s);
}

void    format_oct_o(va_list ap, t_write *wr)
{
    char    *s;
    int     x;
    int     max;
    t_ull   ull;
    
    if (wr->param->lenght && wr->type[wr->param->lenght](&ull, ap, 1, NULL))
        s = ft_utoa_base(ull, 8, 0);
    else
        s = ft_utoa_base((unsigned int)va_arg(ap, int), 8, 0);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['#'] && *s != '0')
        max = max + 1;
    if (wr->param->flags['-'])
        flag2Do(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30o(s, wr, &x, &max);
    else
        flag20o(s, wr, &x, &max);
    free(s);
}