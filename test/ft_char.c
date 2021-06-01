#include "ft_printf.h"

int ft_char(va_list ap, t_flags *flags, int count)
{
    char c;
    char *tmp;

    c = va_arg(ap, int);
    tmp = ft_width((flags->width) - 1);
    count += 1;
    if (flags->width <= 1)
        write(1, &c, 1);
    if (flags->flag_minus == 1 && flags->width > 1)
    {
        write(1, &c, 1);
        while (*tmp)
        {
            write(1, &(*tmp++), 1);
            count++;
        }
    }
    if (flags->flag_minus == 0 && flags->width > 1)
    {
        while (*tmp)
        {
            write(1, &(*tmp++), 1);
            count++;
        }
        write(1, &c, 1);
    }
    return (count);
}