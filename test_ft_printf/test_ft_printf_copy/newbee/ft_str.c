#include "ft_printf.h"

int ft_str(va_list ap, t_flags flags, int count)
{
    char *s;
    int dot;
    int len;

    s = va_arg(ap, char *);
    if (!s)
    {
        count += ft_str_null(flags, count);
    }
    else
    {
        len = ft_strlen(s);
        dot = flags.dot;
        if ((flags.dot >= len || flags.dot == -1) && flags.width <= len)
        {
            ft_putstr_fd(s, 1);
            count += len;
        }
        else if ((flags.dot >= len || flags.dot == -1) && flags.p_star == 0 && flags.width > len && flags.minus == 0)
        {
            ft_width((flags.width) - len);
            ft_putstr_fd(s, 1);
            count += flags.width;
        }
        else if ((flags.dot >= len || flags.dot == -1) && flags.width > len && (flags.p_star == 1 || flags.minus == 1))
        {
            ft_putstr_fd(s, 1);
            ft_width((flags.width) - len);
            count += flags.width;
        }
        else if (flags.dot == 0)
        {
            if (flags.width)
            {
                ft_width(flags.width); //учесть отрицательные значения, ведут себя как положительные
                count += flags.width;
            }
            else
                return (count);
        }
        else if (flags.dot < len && flags.dot > 0 && flags.width <= flags.dot)
        {
            while (dot--)
                write(1, &(*s++), 1);
            count += flags.dot;
        }
        else if (flags.dot < len && flags.dot > 0 && flags.width > flags.dot && flags.minus == 0)
        {
            ft_width((flags.width) - (flags.dot));
            while (dot--)
                write(1, &(*s++), 1);
            count += flags.width;
        }
        else if (flags.dot < len && flags.dot > 0 && flags.width > flags.dot && flags.minus == 1)
        {
            while (dot--)
                write(1, &(*s++), 1);
            ft_width((flags.width) - (flags.dot));
            count += flags.width;
        }
    }
    return (count);
}