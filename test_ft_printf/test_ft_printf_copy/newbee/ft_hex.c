#include "ft_printf.h"

int ft_hex(va_list ap, t_flags flags, int count)
{
    unsigned long long d;
    char *digit;
    int len;

    d = va_arg(ap, unsigned long long);
    digit = ft_itoa_hex(d, flags);
    len = ft_strlen(digit);

    if (d == 0 && flags.dot == 0)
    {
        if (flags.width != 0)
        {
            ft_width(flags.width);
            count += flags.width;
        }
        else
        {
            free(digit);
            return (count);
        }
    }
    else if (flags.dot <= len && flags.width <= len)
    {
        ft_putstr_fd(digit, 1);
        count += len;
    }
    else if (flags.dot > len && (flags.width <= flags.dot)) //если число отриц то выносим минус за точность
    {
        ft_zero((flags.dot) - len);
        ft_putstr_fd(digit, 1);
        count += flags.dot;
    }
    else if (flags.dot <= len && flags.width > len && flags.minus == 0 && flags.p_star == 0 && (flags.dot > -1 || flags.zero == 0))
    {
        ft_width((flags.width) - len);
        ft_putstr_fd(digit, 1);
        count += flags.width;
    }
    else if (flags.dot <= len && flags.width > len && (flags.minus == 1 || flags.p_star == 1))
    {
        ft_putstr_fd(digit, 1);
        ft_width((flags.width) - len);
        count += flags.width;
    }
    else if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 0)
    {
        ft_width((flags.width) - flags.dot);
        ft_zero((flags.dot) - len);
        ft_putstr_fd(digit, 1);
        count += flags.width;
    }
    else if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 1)
    {
        ft_zero((flags.dot) - len);
        ft_putstr_fd(digit, 1);
        ft_width((flags.width) - flags.dot);
        count += flags.width;
    }
    else if (flags.width > len && flags.dot == -1 && flags.zero == 1)
    {
        ft_zero((flags.width) - len);
        ft_putstr_fd(digit, 1);
        count += flags.width;
    }
    free(digit);
    return (count);
}