#include "ft_printf.h"

int ft_char(va_list ap, t_flags flags, int count)
{
    char c;

    c = (char)va_arg(ap, int);
    count += 1;
    if (flags.width <= 1)
        write(1, &c, 1);
    if (flags.minus == 1 && flags.width > 1)
    {
        write(1, &c, 1);
        ft_width((flags.width) - 1);
        count += flags.width;
    }
    if (flags.minus == 0 && flags.width > 1)
    {
        ft_width((flags.width) - 1);
        write(1, &c, 1);
        count += flags.width;
    }
    return (count);
}