#include "ft_printf.h"

int ft_str_null(t_flags flags, int count)
{
    char *s;
    int dot;
    int len;

    s = "(null)";
    len = 6;
    dot = flags.dot;
    if ((flags.dot >= len || flags.dot == -1) && flags.width <= len)
    {
        ft_putstr_fd(s, 1);
        count += len;
    }
    if ((flags.dot >= len || flags.dot < 0) && flags.width > len && flags.minus == 0)
    {
        ft_width((flags.width) - len);
        ft_putstr_fd(s, 1);
        count += flags.width;
    }
    if ((flags.dot >= len || flags.dot < 0) && flags.width > len && flags.minus == 1)
    {
        ft_putstr_fd(s, 1);
        ft_width((flags.width) - len);
        count += flags.width;
    }
    if (flags.dot == 0)
    {
        if (flags.width)
        {
            ft_width(flags.width); //учесть отрицательные значения, ведут себя как положительные
            count += flags.width;
        }
        else
            return (count);
    }
    if (flags.dot < len && flags.dot > 0 && flags.width < flags.dot)
    {
        while (dot--)
            write(1, &(*s++), 1);
        count += flags.dot;
    }
    if (flags.dot < len && flags.dot > 0 && flags.width > flags.dot && flags.minus == 0)
    {
        ft_width((flags.width) - (flags.dot));
        while (dot--)
            write(1, &(*s++), 1);
        count += flags.width;
    }
    if (flags.dot < len && flags.dot > 0 && flags.width > flags.dot && flags.minus == 1)
    {
        while (dot--)
            write(1, &(*s++), 1);
        ft_width((flags.width) - (flags.dot));
        count += flags.width;
    }
    return (count);
}