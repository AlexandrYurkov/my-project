#include "ft_printf.h"

int ft_pointr(va_list ap, t_flags flags, int count)
{
    unsigned long long d;
    char *digit;
    int len;

    d = va_arg(ap, unsigned long long);
    digit = ft_itoa_hex(d, flags);
    len = ft_strlen(digit) + 2;
    if (flags.width <= len)
    {
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(digit, 1);
        count += len;
    }
    if (flags.width > len && flags.minus == 0 && flags.p_star == 0)
    {
        ft_width(flags.width - len);
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(digit, 1);
        count += flags.width;
    }
    if (flags.width > len && (flags.minus == 1 || flags.p_star == 1))
    {
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(digit, 1);
        ft_width(flags.width - len);
        count += flags.width;
    }
    if (digit)
    free(digit);
    return (count);
}