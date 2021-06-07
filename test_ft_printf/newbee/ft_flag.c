#include "ft_printf.h"

int ft_flag(const char *str, va_list ap, int i, t_flags *flags)
{
    int j = 0;
    while (str[i])
    {
        if (str[i] == '0' && j == 0)// ошибка записывает ноль
            flags->zero = 1;
        if (str[i] == '-')
        {
            flags->minus = 1;
            flags->zero = 0;
        }
        if (str[i] == '*' || ((str[i] >= '0' && str[i] <= '9') && flags->width == 0))
        {
            flags->width = ft_stardot(str, ap, i, &flags);
        }
        if (str[i] == '.')
        {
            i++;
            if (str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
                flags->dot = ft_stardot(str, ap, i, &flags);
            else
            {
                flags->dot = 0;
                i--;
            }
        }
        if (ft_spec(str[i], "cspdiuxX%"))
        {
            flags->type = str[i];
            break;
        }
        i++;
        j++;
    }
    return (i);
}