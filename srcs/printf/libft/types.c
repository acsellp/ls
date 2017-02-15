#include "ft_printf.h"

int     type_hh(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
    unsigned char   uc;
    signed char     sc;
    unsigned short  us;

    if (sw == 1)
    {
        uc = (unsigned char)va_arg(ap, int);
        *ull = (t_ull)uc;
    }
    else if (sw == 0)
    {
        sc = (signed char)va_arg(ap, int);
        *ll = (t_ll)sc;
    }
    else if (sw == 2)
    {
        us = (unsigned short)va_arg(ap, int);
        *ull = (t_ull)us;
    }
    else if (sw == 3)
    {
        us = (unsigned short)va_arg(ap, int);
        *ll = (t_ll)us;
    }
    return (1);
}

int     type_h(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
    unsigned short  us;
    short           s;

    if (sw == 1 || sw == 2)
    {
        us = (unsigned short)va_arg(ap, int);
        *ull = (t_ull)us;
    }
    else if (sw == 0)
    {
        s = (short)va_arg(ap, int);
        *ll = (t_ll)s;
    }
    else if (sw == 3)
    {
        us = (unsigned short)va_arg(ap, int);
        *ll = (t_ll)us;
    }
    return (1);
}

int     type_l(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
    unsigned long   ul;
    long            l;

    if (sw == 1 || sw == 2)
    {
        ul = (t_ll)va_arg(ap, t_ll);
        *ull = (t_ull)ul;
    }
    else if (sw == 0 || sw == 3)
    {
        l = va_arg(ap, long);
        *ll = (t_ll)l;
    }
    return (1);
}

int     type_ll(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
    t_ull   ul;
    t_ll    l;

    if (sw == 1 || sw == 2)
    {
        ul = (t_ull)va_arg(ap, t_ll);
        *ull = ul;
    }
    else if (sw == 0 || sw == 3)
    {
        l = va_arg(ap, t_ll);
        *ll = l;
    }
    return (1);
}