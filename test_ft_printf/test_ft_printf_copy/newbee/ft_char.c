#include "ft_printf.h"

int ft_char(va_list ap, t_flags flags, int count)
{
    char c;

    if (flags.type == '%')
        c = '%';
    else
        c = (char)va_arg(ap, int);

    if (flags.width <= 1)
    {
        write(1, &c, 1);
        count += 1;
    }
    if (flags.width > 1 && (flags.minus == 1 || flags.p_star == 1))
    {
        write(1, &c, 1);
        ft_width((flags.width) - 1);
        count += flags.width;
    }
    if (flags.minus == 0 && flags.width > 1 && c == '%' && flags.zero == 1)
    {
        ft_zero((flags.width) - 1);
        write(1, &c, 1);
        count += flags.width;
    }
    if (flags.width > 1 && flags.minus == 0 && flags.zero == 0 && flags.p_star == 0)
    {
        ft_width((flags.width) - 1);
        write(1, &c, 1);
        count += flags.width;
    }
    return (count);
}