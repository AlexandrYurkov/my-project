#include "ft_printf.h"

t_flags ft_flag(char *str, va_list ap, t_flags *flags)
{
    if (*str == '-')
        flags->flag_minus = 1;
    if (*str == '0')
        flags->flag_zero = 1;
    if (*str == '*' || (*str >= 0 && *str <= 9))
        flags->width = ft_stardot(str, ap);
    if (*str == '.')
    {
        str++;
        flags->dot = ft_stardot(str, ap);
    }
    if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
    {
        flags->type = ft_spec(*str, "cspdiuxX%");
    }
    return (*flags);
}