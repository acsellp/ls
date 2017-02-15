
#include "ft_printf.h"

int     isflag(char c)
{
    if (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+')
        return (1);
    return (0);
}

void    ftflags(char *fmt, int *i, t_write *wr)
{
    while (isflag(*(fmt + *i)))
    {
        wr->param->flags[(int)*(fmt + *i)] = '\x01';
        *i += 1;   
    }
}

void    ftwidth(char *fmt, int *i, t_write *wr)
{
    while (ft_isdigit(*(fmt + *i)))
    {
        wr->param->width = wr->param->width * 10 + (*(fmt + *i) - '0');
        *i += 1;
    }
}

void    ftprec(char *fmt, int *i, t_write *wr)
{
    wr->param->flags['.'] = '\x01';
    *i += 1;
    if (!ft_isdigit(fmt[*i]))
        while (fmt[*i] == '.' || ft_isdigit(fmt[*i]))
            *i += 1;
    else
    {
        while (ft_isdigit(*(fmt + *i)))
        {
            wr->param->prec = wr->param->prec * 10 + (*(fmt + *i) - '0');
                *i += 1;
        }
    }
}

int     islenght(char c)
{
    if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
        return (1);
    return (0);
}