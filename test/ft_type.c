#include "ft_printf.h"

int ft_type(va_list ap, t_flags *flags)
{
    int count;

    count = 0;
    if(flags->type  == 'c')
        ft_char(ap, flags, count);
    if(flags->type  == 's')
        ft_string(ap, flags, count);
    /*if(flags->type  == 'd' || flags->type  == 'i')
        ft_int
    if(flags->type  == 'p')
        ft_pointr
    if(flags->type  == 'x')
        ft_hex
    if(flags->type  == 'X')
        ft_HEX
    if(flags->type  == '%')
        ft_percent*/
    return (count);
}