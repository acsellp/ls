#include "ft_printf.h"

t_write *ftconvert(va_list ap, char *fmt)
{
	t_write    *wr;
    int        i;

    i = 0;
    wr = init_twrite();
	while (*(fmt + i) != '\0')
	{   
        if (*(fmt + i) == '{')
            fmt += ftcolor(fmt + i);
        if (*(fmt + i) != '\0' && *(fmt + i) != '%')
            wr->cnt += wr->ftwrite(fmt + i, 1);
        else if (*(fmt + i + 1) != '\0')
        {
            get_params(wr, fmt, &i);
            if (*(fmt + i) == '\0')
                break;
            else
                check_specs(wr, fmt, i, ap);
        }
		i++;
	}
	va_end(ap);
    return (wr);
}
  
int     ft_printf(const char *fmt, ...)
{
    va_list     ap;
    int         ret;
    t_write     *wr;

    if (!fmt)
        return (0);
	va_start(ap, fmt);
	wr = ftconvert(ap, (char*)fmt);
    ret = wr->cnt;
    free(wr->type);
    free(wr->param->flags);
    free(wr->param);
    free(wr);
    return (ret);
}