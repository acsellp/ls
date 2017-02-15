#include "ft_printf.h"

t_type  *init_type(void)
{
    t_type *ret;

    ret = (t_type*)malloc(sizeof(t_type) * 130);
    ret['H'] = type_hh;
    ret['h'] = type_h;
    ret['L'] = type_ll;
    ret['l'] = type_l;
    ret['j'] = type_j;
    ret['z'] = type_z;
    ret[40] = type_l;
    return (ret);
}

void    extra_spec(t_write *wr, char *fmt, int i)
{
    char c;
    
    c = ' ';
    if (wr->param->flags['0'])
        c = '0';
    if (!wr->param->flags['-'])
    {
        while (--wr->param->width)
            wr->cnt += wr->ftwrite(&c, 1);
        wr->cnt += wr->ftwrite(fmt + i, 1);
    }
    else
    {
        wr->cnt += wr->ftwrite(fmt + i, 1); 
        while (--wr->param->width)
            wr->cnt += wr->ftwrite(&c, 1);
    }    
}

void    check_specs(t_write *wr, char *fmt, int i, va_list ap)
{
    if (ft_strchr(specs, *(fmt + i)))
    {
        if (!ftspec(ap, *(fmt + i), wr))
            ftspec_(ap, *(fmt + i), wr);
    }
    else if (wr->param->width && !ft_strchr(specs, *(fmt + i)))
        extra_spec(wr, fmt, i);
    else
        wr->cnt += wr->ftwrite(fmt + i, 1);
}

void    get_params(t_write *wr, char *fmt, int *i)
{
    *i += 1;
    wr->param->width = 0;
    wr->param->prec = 0;
    wr->param->lenght = 0;
    clear_flags(wr->param->flags);
    while (*(fmt + *i) && ft_strchr(params, *(fmt + *i)))
    {
        if (isflag(*(fmt + *i)))
        {
            wr->param->flags[(int)*(fmt + *i)] = *(fmt + *i);
            *i += 1;
        }
        else if (ft_isdigit(*(fmt + *i)))
            ftwidth(fmt, i, wr);
        else if (*(fmt + *i) == '.')
            ftprec(fmt, i, wr);
        else if (islenght(*(fmt + *i)))
            ftlenght(fmt, i, wr);
    }
}

t_write *init_twrite()
{
    t_write *wr;
    
    wr = (t_write*)malloc(sizeof(t_write));
    wr->cnt = 0;
    wr->ftwrite = &ftwrite;
    wr->param = (t_param*)malloc(sizeof(t_param));
    wr->param->flags = (uint8_t*)malloc(sizeof(uint8_t) * 60);
    wr->type = init_type();
    return (wr);
}