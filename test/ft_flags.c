#include "ft_printf.h"

int ft_flags(char *str, va_list ap, int i, t_flags *flags)
{
    int index = i;

    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == ' ')
            {
                while (*str == ' ')
                {
                    str++;
                }
                flags->space = 1;
            }
            ft_flag(str, ap, flags);
            ft_type(ap, flags);
        }
        else
        {
            write(1, &str, 1);
        }
        str++;
        index++;
    }

    return index;
}