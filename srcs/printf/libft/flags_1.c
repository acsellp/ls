#include "ft_printf.h"

void flag2D(char *s, t_write *wr, int *x)
{
    wr->param->width -= *x > wr->param->prec ? *x : wr->param->prec;
    if (wr->param->flags['&'])
    {
        wr->cnt += wr->ftwrite("-", 1);
        wr->param->width--;
    }
    else if (wr->param->flags['+'])
    {
        wr->cnt += wr->ftwrite("+", 1);
        wr->param->width--;
    }
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
    while (0 < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
}

void    flag20_(char *s, t_write *wr, int *max, int *x)
{
    while (*max < wr->param->width--)
        wr->cnt += wr->ftwrite(" ", 1);
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
}

void    flag20(char *s, t_write *wr, int *x, int *max)
{
    if ((wr->param->flags['&'] || wr->param->flags['+']) && wr->param->width--)
        while (*max <= wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
    if (wr->param->flags['&'])
        wr->cnt += wr->ftwrite("-", 1);
    else if (wr->param->flags['+'])
        wr->cnt += wr->ftwrite("+", 1);
    else if (!wr->param->prec && *s == '0' && wr->param->flags['.'])
    {
        while (0 < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
        return ;
    }
    else if (wr->param->flags['0'] \
             && !wr->param->flags['.'] && wr->param->width != 0)
    {
        while (*max < --wr->param->width)
            wr->cnt += wr->ftwrite(" ", 1);
        wr->cnt += wr->ftwrite("0", 1);
    }
    flag20_(s, wr, max, x);
}

void    flag30(char *s, t_write *wr, int *x)
{
    if (wr->param->flags['&'])
    {
        wr->cnt += wr->ftwrite("-", 1);
        wr->param->width--;
        while (*x < wr->param->width--)
            wr->cnt += wr->ftwrite("0", 1);
    }
    else if (wr->param->flags['+'])
    {
        wr->cnt += wr->ftwrite("+", 1);
        wr->param->width--;
        while (*x < wr->param->width--)
            wr->cnt += wr->ftwrite("0", 1);
    }
    while (*x < wr->param->width--)
        wr->cnt += wr->ftwrite("0", 1);
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
}