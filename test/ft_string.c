#include "ft_printf.h"

int ft_string(va_list ap, t_flags *flags, int count)
{
    char *s = NULL;
    char *tmp = NULL;
    char *empty = NULL;
    int tot;
    int len;

    s = va_arg(ap, char *);
    len = ft_strlen(s);
    tmp = ft_width((flags->width) - len);

    tot = flags->dot;

    if (flags->dot >= len && flags->width <= len)
    {
        ft_putstr_fd(s, 1);
        count += len;
    }
    if ((flags->dot >= len || flags->dot < 0) && flags->width > len && flags->flag_minus == 0)
    {
        ft_putstr_fd(tmp, 1);
        ft_putstr_fd(s, 1);
        count += len + ft_strlen(tmp);
    }
    if ((flags->dot >= len || flags->dot < 0) && flags->width > len && flags->flag_minus == 1)
    {
        ft_putstr_fd(s, 1);
        ft_putstr_fd(tmp, 1);
        count += len + ft_strlen(tmp);
    }
    if (flags->dot == 0 && flags->width > len && flags->flag_minus == 1)
    {
        empty = ft_width(flags->width);
        ft_putstr_fd(empty, 1);
        count += flags->width;
    }
    if (flags->dot <= len)
    {
        while (tot--)
            write(1, &(*s++), 1);
        count += flags->dot;
    }
    if (flags->dot <= len && flags->width > flags->dot && flags->flag_minus == 0)
    {
        empty = ft_width((flags->width) - (flags->dot));
        ft_putstr_fd(empty, 1);
        while (tot--)
            write(1, &(*s++), 1);
        count += flags->width;
    }
    if (flags->dot <= len && flags->width > flags->dot && flags->flag_minus == 1)
    {
        empty = ft_width((flags->width) - (flags->dot));
        while (tot--)
            write(1, &(*s++), 1);
        ft_putstr_fd(empty, 1);
        count += flags->width;
    }
    return (count);
}