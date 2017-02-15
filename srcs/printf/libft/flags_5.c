#include "ft_printf.h"

void    flag2Ds(char *s, t_write *wr, int *x, int *min)
{
    if (*x)
        wr->cnt += wr->ftwrite(s, *min);
    while (*min < wr->param->width--)
            wr->cnt += wr->ftwrite(" ", 1);
}

void    flag20s(char *s, t_write *wr, int *x, int *min)
{
    char c;

    c = ' ';
    if (wr->param->flags['0'])
        c = '0';
    while (*min < wr->param->width--)
            wr->cnt += wr->ftwrite(&c, 1);
    if (*x)
        wr->cnt += wr->ftwrite(s, *min);
}

void    flag30s(char *s, t_write *wr, int *x, int *min)
{
    char c;
    
    c = ' ';
    if (wr->param->flags['0'])
        c = '0';
    if (wr->param->flags['-'])
    {
        wr->cnt += wr->ftwrite(s, *min);
        while (*min < wr->param->width--)
                wr->cnt += wr->ftwrite(&c, 1);
    }
    else
    {
        while (*min < wr->param->width--)
                wr->cnt += wr->ftwrite(&c, 1);
        wr->cnt += wr->ftwrite(s, *min);
    }
    (void)x;
}