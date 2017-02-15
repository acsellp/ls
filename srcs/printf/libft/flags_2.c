#include "ft_printf.h"

void    flag2Dx(char *s, t_write *wr, int *x, int *max)
{
    if (wr->param->flags['#'] && *s != '0')
        wr->cnt += wr->ftwrite("0x", 2);
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
    while (*max < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
}

void    flag20x(char *s, t_write *wr, int *x, int *max)
{
    if (!wr->param->prec && *s == '0' && wr->param->flags['.'])
    {
        while (0 < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
        return ;
    }
    while (*max < wr->param->width--)
        wr->cnt += wr->ftwrite(" ", 1);

    if (wr->param->flags['#'] && *s != '0')
        wr->cnt += wr->ftwrite("0x", 2);
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
}

void    flag30x(char *s, t_write *wr, int *x, int *max)
{
    if (wr->param->flags['#'] && *s != '0')
        wr->cnt += wr->ftwrite("0x", 2);
    while (*max < wr->param->width--)
        wr->cnt += wr->ftwrite("0", 1);
    while (wr->param->prec-- > *x)
        wr->cnt += wr->ftwrite("0", 1);
    wr->cnt += wr->ftwrite(s, *x);
}