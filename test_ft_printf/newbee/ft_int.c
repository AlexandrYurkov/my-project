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
    if (flags.space == 1)
    {
        write(1, " ", 1);
        count++;
    }
    if (flags.dot <= len && flags.width <= len) // тест 20 попадает сюда
    {
        if (flags.dot == len && flags.zero == 0)
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
        else if (d == 0 && flags.dot == 0 && flags.width == 0)
        {
            free(digit);
            free(tmp);
            return (count);
        }
        else if (flags.dot == 0 && d == 0 && flags.width == len)
        {
            ft_width(flags.width);
            count += flags.width;
        }
        else
        {
            ft_putstr_fd(digit, 1);
            count += len;
        }
    }
    else if (flags.dot > len && (flags.width <= flags.dot)) //если число отриц то выносим минус за точность
    {
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
            count += flags.dot + 1;
        }
        else if (flags.p_star == 1 && flags.width == 0)
        {
            ft_putstr_fd(digit, 1);
            count += len;
        }
        else if (flags.width > len && flags.p_star == 1)
        {
            ft_zero((flags.width) - len);
            ft_putstr_fd(digit, 1);
            count += flags.width;
        }
        else
        {
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
            count += flags.dot;
        }
    }
    else if (flags.dot <= len && flags.width > len)
    {
        if (flags.dot == 0 && d == 0)
        {
            ft_width(flags.width);
            count += flags.width;
        }
        else if (flags.zero == 0 && flags.minus == 0 && flags.p_star == 0 && d != 0)
        {
            if (d < 0 && flags.dot == len)
            {
                ft_width((flags.width) - (flags.dot + 1));
                write(1, "-", 1);
                ft_zero((flags.dot) - (len - 1));
                ft_putstr_fd(tmp, 1);
            }
            else
            {
                ft_width((flags.width) - len);
                ft_putstr_fd(digit, 1);
            }
            count += flags.width;
        }
        else if (flags.zero == 0 && d != 0 && (flags.minus == 1 || flags.p_star == 1))
        {
            if (d < 0 && flags.dot == len)
            {
                write(1, "-", 1);
                ft_zero((flags.dot) - (len - 1));
                ft_putstr_fd(tmp, 1);
                ft_width((flags.width) - (flags.dot + 1));
            }
            else
            {
                ft_putstr_fd(digit, 1);
                ft_width((flags.width) - len);
            }
            count += flags.width;
        }
        else if (flags.zero == 1 && flags.dot == -1)
        {
            if (d < 0)
            {
                write(1, "-", 1);
                ft_zero((flags.width) - len);
                ft_putstr_fd(tmp, 1);
            }
            else
            {
                ft_zero((flags.width) - len);
                ft_putstr_fd(digit, 1);
            }
            count += flags.width;
        }
        else if (flags.zero == 1 && flags.dot > -1)
        {
            if (d < 0 && flags.dot == len)
            {
                ft_width((flags.width) - (flags.dot + 1));
                write(1, "-", 1);
                ft_zero((flags.dot) - (len - 1));
                ft_putstr_fd(tmp, 1);
            }
            else
            {
                ft_width((flags.width) - len);
                ft_putstr_fd(digit, 1);
            }
            count += flags.width;
        }
        else if (flags.zero == 0 && flags.dot <= 0 && d == 0 && flags.minus == 0)
        {
            ft_width((flags.width) - len);
            ft_putstr_fd(digit, 1);
            count += flags.width;
        }
        else if (flags.zero == 0 && flags.dot <= 0 && d == 0 && flags.minus == 1)
        {
            ft_putstr_fd(digit, 1);
            ft_width((flags.width) - len);
            count += flags.width;
        }
    }
    else if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 1)
    {
        if (d < 0)
        {
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
            ft_width((flags.width) - (flags.dot + 1));
        }
        else
        {
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
            ft_width((flags.width) - flags.dot);
        }
        count += flags.width;
    }
    else if (flags.dot > len && (flags.width > flags.dot) && flags.minus == 0)
    {
        if (d < 0)
        {
            ft_width((flags.width) - (flags.dot + 1));
            write(1, "-", 1);
            ft_zero((flags.dot) - (len - 1));
            ft_putstr_fd(tmp, 1);
        }
        else
        {
            ft_width((flags.width) - flags.dot);
            ft_zero((flags.dot) - len);
            ft_putstr_fd(digit, 1);
        }
        count += flags.width;
    }
    if (digit)
    free(digit);
    if (tmp)
    free(tmp);
    return (count);
}