#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int width;
    char type;
    int space;
    int p_star;
}              t_flags;

int ft_printf(const char *c, ...);
int ft_parse(const char *str, va_list ap);
int ft_flag(const char *str, va_list ap, int i, t_flags *flags);
int ft_char(va_list ap, t_flags flags, int count);
int ft_width(int width);
int ft_type(va_list ap, t_flags flags);
int ft_spec(char c, char *str);
int ft_stardot(const char *str, va_list ap, int i, t_flags **flags);
int ft_str(va_list ap, t_flags flags, int count);
int ft_int(va_list ap, t_flags flags, int count);
int ft_zero(int zero);
int ft_unsig(va_list ap, t_flags flags, int count);
int ft_hex(va_list ap, t_flags flags, int count);
int ft_pointr(va_list ap, t_flags flags, int count);
char    *ft_unsig_itoa(unsigned int nb);
char    *ft_itoa_hex(unsigned long long n, t_flags flags);
int ft_str_null(t_flags flags, int count);

# endif