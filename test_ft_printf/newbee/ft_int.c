#include "ft_printf.h"

int ft_int(va_list ap, t_flags flags, int count)
{
    int d;
    char *digit;
    char *tmp;
    int len;

    d = va_arg(ap, int);
    digit = ft_itoa(d);
    tmp = ft_itoa(d * (-1));
    len = ft_strlen(digit);
    if (flags.dot <= len && flags.width <= len)
    {
        ft_putstr_fd(digit, 1);
        count += len;
    }
    if (flags.dot > len && (flags.width <= flags.dot)) //если число отриц то выносим минус за точность
    {
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
            count++;
        }
        else
        {
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
        }
        count += flags.dot;
    }
    if (flags.dot <= len && flags.width > len && flags.minus == 0 && flags.zero == 0)
    {
        ft_width((flags.width) - len);
        ft_putstr_fd(digit, 1);
        count += flags.width;
    }
    if (flags.dot <= len && flags.width > len && flags.minus == 1)
    {
        ft_putstr_fd(digit, 1);
        ft_width((flags.width) - len);
        count += flags.width;
    }
    if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 0)
    {
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
            count++;
        }
        else
        {
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
        }
        if (d < 0)
            ft_width((flags.width) - (flags.dot + 1));
        else
            ft_width((flags.width) - flags.dot);
        count += flags.width;
    }
    if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 1)
    {
        if (d < 0)
            ft_width((flags.width) - (flags.dot + 1));
        else
            ft_width((flags.width) - flags.dot);
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
            count++;
        }
        else
        {
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
        }
        count += flags.width;
    }
    if (flags.width > len && flags.dot == -1 && flags.zero == 1)
    {
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.width) - len);
            ft_putstr_fd(tmp, 1);
            count++;
        }
        else
        {
            ft_zero((flags.width) - len);
            ft_putstr_fd(digit, 1);
        }
        count += flags.width;
    }
    free(digit);
    free(tmp);
    return (count);
}