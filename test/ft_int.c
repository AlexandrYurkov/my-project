#include "ft_printf.h"

int ft_int(va_list ap, t_flags *flags, int count)
{
    int d;
    char *digit;
    char *tmp;
    char *empty;
    //int Dot;
    int len;

    d = va_arg(ap, int);
    digit = ft_itoa(d);
    len = ft_strlen(digit);
    tmp = ft_zero((flags->width) - len);
    empty = ft_width((flags->width) - len);
    //int Dot = flags->dot;

    if (flags->dot <= len && flags->width <= len)
    {
        ft_putstr_fd(digit, 1);
        count += len;
    }
    if (flags->dot >= len && (flags->width <= flags->dot))
    {
        ft_putstr_fd(tmp, 1);
        ft_putstr_fd(digit, 1);
        count += len + ft_strlen(tmp);
    }
    if (flags->dot <= len && flags->width > len && flags->flag_minus == 0)
    {
        ft_putstr_fd(empty, 1);
        ft_putstr_fd(digit, 1);
        count += len + ft_strlen(empty);
    }
    if (flags->dot <= len && flags->width > len && flags->flag_minus == 1)
    {
        ft_putstr_fd(digit, 1);
        ft_putstr_fd(empty, 1);
        count += len + ft_strlen(empty);
    }
    if (flags->dot > len && (flags->width > flags->dot) && flags->flag_minus == 0)
    {
        ft_putstr_fd(tmp, 1);
        ft_putstr_fd(digit, 1);
        ft_putstr_fd(empty, 1);
        count += len + ft_strlen(tmp) + ft_strlen(empty);
    }
    if (flags->dot > len && (flags->width > flags->dot) && flags->flag_minus == 1)
    {
        ft_putstr_fd(empty, 1);
        ft_putstr_fd(tmp, 1);
        ft_putstr_fd(digit, 1);
        count += len + ft_strlen(tmp) + ft_strlen(empty);
    }


    // учесть флаг ноль при ширине>len

    /*if (flags->dot <= len && flags->width > flags->dot && flags->flag_minus == 0)
    {
        empty = ft_width((flags->width) - (flags->dot));
        ft_putstr_fd(empty, 1);
        while (dot--)
            write(1, &(*s++), 1);
        count += flags->width;
    }
    if (flags->dot <= len && flags->width > flags->dot && flags->flag_minus == 1)
    {
        empty = ft_width((flags->width) - (flags->dot));
        while (dot--)
            write(1, &(*s++), 1);
        ft_putstr_fd(empty, 1);
        count += flags->width;
    }*/
    return (count);
}