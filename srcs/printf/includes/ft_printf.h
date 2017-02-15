#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "./../libft/libft.h"
# include "./../libft/typedefs.h"
# define specs "pdiDoOuUxXHsScCf%"
# define params ". #0123456789-+hljz"

typedef int     (*t_type)(t_ull *, va_list, uint8_t, t_ll *);
typedef struct  s_param
{
    uint8_t     *flags;
    int         width;
    uint8_t     prec;
    uint8_t     lenght;
}               t_param;
typedef struct  s_write
{
    int         (*ftwrite)(char *, int);
    int         cnt;
    t_type      *type;
    t_param     *param;
}               t_write;
typedef void    (*t_format)(va_list, t_write *);

int             ftcolor(char *fmt);
void	        ft_putwchar(wchar_t c);
int             ft_flags_wc(t_write *wr, wchar_t c,int len);
void            wchar_char(wchar_t c, int i, char *ret);
char			*wstr_to_str(wchar_t *s);
int             ft_wstrlen(wchar_t *s);
void            clear_flags(uint8_t *flags);
int             wcharlen(wchar_t wc);
int             type_hh(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int             type_h(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int             type_ll(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int             type_l(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int             type_j(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
int             type_z(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll);
void            flag2D(char *s, t_write *wr, int *sz);
void            flag20(char *s, t_write *wr, int *sz, int *max);
void            flag30(char *s, t_write *wr, int *sz);
void            flag2Dx(char *s, t_write *wr, int *sz, int *max);
void            flag20x(char *s, t_write *wr, int *sz, int *max);
void            flag30x(char *s, t_write *wr, int *sz, int *max);
void            flag2DX(char *s, t_write *wr, int *sz, int *max);
void            flag20X(char *s, t_write *wr, int *sz, int *max);
void            flag30X(char *s, t_write *wr, int *sz, int *max);
void            flag2Do(char *s, t_write *wr, int *sz, int *max);
void            flag20o(char *s, t_write *wr, int *sz, int *max);
void            flag30o(char *s, t_write *wr, int *sz, int *max);
void            flag2Ds(char *s, t_write *wr, int *sz, int *min);
void            flag20s(char *s, t_write *wr, int *sz, int *min);
void            flag30s(char *s, t_write *wr, int *sz, int *min);
void            ft_prec_width_wstr(char *str, t_write *wr);
void            ftreadparams(va_list ap, char *fmt, int *i, t_write *wr);
void            ftflags(char *fmt, int *i, t_write *wr);
void            ftwidth(char *fmt, int *i, t_write *wr);
void            ftprec(char *fmt, int *i, t_write *wr);
void            ftlenght(char *fmt, int *i, t_write *wr);
int             ftspec(va_list ap, char spec, t_write *wr);
int             ftspec_(va_list ap, char spec, t_write *wr);
t_write         *init_twrite(void);
void            get_params(t_write *wr, char *fmt, int *i);
void            check_specs(t_write *wr, char *fmt, int i, va_list ap);
int             islenght(char c);
int             isflag(char c);
void            format_unsign_u(va_list ap, t_write *wr);
void            format_unsign_U(va_list ap,  t_write *wr);
void            format_address(va_list ap, t_write *wr);
void            format_oct_o(va_list ap, t_write *wr);
void            format_oct_O(va_list ap, t_write *wr);
void            format_hex_x(va_list ap, t_write *wr);
void            format_hex_X(va_list ap, t_write *wr);
void            format_number_d(va_list ap,  t_write *wr);
void            format_number_D(va_list ap, t_write *wr);
void            format_char_c(va_list ap, t_write *wr);
void            format_char_w(va_list ap, t_write *wr);
void            format_string_s(va_list ap, t_write *wr);
void            format_string_w(va_list ap, t_write *wr);
void            format_perc(va_list ap, t_write *wr);
void            format_float(va_list ap, t_write *wr);
char            *ft_strjoindel(char const *s1, char const *s2, int vect);
int             ft_bytes(t_ull b, int i, int bits);
t_write         *ftconvert(va_list ap, char *fmt);
int			    ft_printf(const char *fmt, ...);
char            *ft_itoa_base(t_ll nr, int base);
t_ll    	    ft_atoi_base(char *s, int base);
char            *ft_strndup_printf(char *s, size_t sz);
t_ll    	    ft_pow(int n, int p);
char            *ft_utoa_base(t_ull n, int base, int up);
void            pointer_address(void *p, t_write *wr);
int             ftwrite(char *s, int);
t_type          *init_type(void);

#endif