#include "ft_printf.h"

int     exclude_type(char c)
{
    if (c == 'L' || c == 'j' || c == 'z')
        return (0);
    return (1);  
}

void    ftlenght(char *fmt, int *i, t_write *wr)
{
    while (islenght(fmt[*i]))
    {
        if (exclude_type(wr->param->lenght))
        {
            if (wr->param->lenght > 0 && (fmt[*i] == 'h' || fmt[*i] == 'l'))
                wr->param->lenght -= 32;
            else
                wr->param->lenght += *(fmt + *i);
        }
        *i += 1;
    }
}

int     ftspec(va_list ap, char spec, t_write *wr)
{
    if (spec == 'd')
        format_number_d(ap, wr);
    else if (spec == 'i')
        format_number_d(ap, wr);
	else if (spec == 'D')
        format_number_D(ap, wr);
    else if (spec == 's')
        format_string_s(ap, wr);
    else if (spec == 'S')
        format_string_w(ap, wr);
	else if (spec == 'x')
         format_hex_x(ap, wr);
	else if (spec == 'X')
         format_hex_X(ap, wr);
	else if (spec == 'f')
         format_float(ap, wr);
    else
        return (0);
    return (1);
}

int     ftspec_(va_list ap, char spec, t_write *wr)
{
    if (spec == 'o')
        format_oct_o(ap,  wr);
	else if (spec == 'O')
        format_oct_O(ap, wr);
	else if (spec == 'u')
        format_unsign_u(ap,  wr);
	else if (spec == 'U')
        format_unsign_U(ap,  wr);
	else if (spec == 'p')
        format_address(ap,  wr);
    else if (spec == 'c')
        format_char_c(ap,  wr);
    else if (spec == 'C')
        format_char_w(ap,  wr);
    else if (spec == '%')
        format_perc(ap,  wr);
    else
        return (0);
    return (1);
}

void    clear_flags(uint8_t *flags)
{
    flags['\x20'] = '\x00';
    flags['\x30'] = '\x00';
    flags['\x2D'] = '\x00';
    flags['\x2B'] = '\x00';
    flags['\x23'] = '\x00';
    flags['\x2E'] = '\x00';
    flags['\x26'] = '\x00';
}