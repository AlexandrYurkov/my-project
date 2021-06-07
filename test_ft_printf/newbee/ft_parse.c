#include "ft_printf.h"

t_flags ft_null_flags(t_flags flags)
{
    flags.minus = 0;
    flags.zero = 0;
    flags.dot = -1;
    flags.type = 0;
    flags.width = 0;
    flags.space = 0;
    flags.p_star = 0;
    return (flags);
}

int ft_parse(const char *str, va_list ap)
{
    t_flags flags;
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            flags = ft_null_flags(flags);
            if (str[i] == ' ')
            {
                while (str[i] == ' ')
                {
                    i++;
                }
                flags.space = 1;
            }
            i = ft_flag(str, ap, i, &flags);
            count += ft_type(ap, flags); // сделать проверку на type
        }
        else
        {
            write(1, &str[i], 1);
            count++;
        }
        i++;
    }
    return (count);
}