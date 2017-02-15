#include "ft_printf.h"

void    format_address(va_list ap, t_write *wr)
{
    pointer_address(va_arg(ap, void*), wr);
}

void    format_unsign_u(va_list ap, t_write *wr)
{
    char    *s;
    t_ull   ull;
    int     x;
    int     max;
    
    if (wr->param->lenght && wr->type[wr->param->lenght](&ull, ap, 1, NULL))
        s = ft_utoa_base(ull, 10, 0);
    else
        s = ft_utoa_base((unsigned int)va_arg(ap, int), 10, 0);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['-'])
        flag2Do(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30o(s, wr, &x, &max);
    else
        flag20o(s, wr, &x, &max);
    free(s);
}

void    format_unsign_U(va_list ap, t_write *wr)
{
    char    *s;
    int     x;
    int     max;
    t_ull   ull;
    
    max = wr->param->lenght;
    if (max && max != 104 && max != 72 && \
        wr->type[wr->param->lenght](&ull, ap, 1, NULL))
        s = ft_utoa_base(ull, 10, 0);
    else
        s = ft_utoa_base((t_ull)va_arg(ap, long int), 10, 0);
    x = ft_strlen(s);
    max = wr->param->prec > x ? wr->param->prec : x;
    if (wr->param->flags['-'])
        flag2Do(s, wr, &x, &max);
    else if (wr->param->flags['0'] && !wr->param->flags['.'])
        flag30o(s, wr, &x, &max);
    else
        flag20o(s, wr, &x, &max);
    free(s);
}

void    format_perc(va_list ap, t_write *wr)
{
    int x;

    x = 1;
    if (wr->param->flags['\x2D'])
    {
        wr->cnt += wr->ftwrite("\x25", 1);
        while (x++ < wr->param->width)
            wr->cnt += wr->ftwrite(" ", 1);
    }
    else
    {
        if (wr->param->flags['0'])
            while (x++ < wr->param->width)
                wr->cnt += wr->ftwrite("0", 1);
        else
            while (x++ < wr->param->width)
                wr->cnt += wr->ftwrite(" ", 1);     
        wr->cnt += wr->ftwrite("\x25", 1);
    }
    (void)ap;
}