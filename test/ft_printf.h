#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
    int flag_minus; //0
    int flag_zero; //0
    int dot; // -1 
    int width; //0
    char type; //0
    int space;
}              t_flags;

int ft_printf(const char *c, ...);
int ft_flags(char *str, va_list ap, int i, t_flags *flags);
t_flags ft_flag(char *str, va_list ap, t_flags *flags);
int ft_star(char *str, va_list ap, t_flags *flags);
int ft_char(va_list ap, t_flags *flags, int count);
char *ft_width(int width);
int ft_stardot(char *str, va_list ap);
int ft_spec(char c, char *str);
int ft_type(va_list ap, t_flags *flags);
int ft_string(va_list ap, t_flags *flags, int count);
char *ft_width(int width);
char *ft_zero(int zero);

# endif