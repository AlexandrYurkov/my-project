#include "ft_printf.h"

int ft_type(va_list ap, t_flags flags)
{
    int count;

    count = 0;
    if (flags.type == 'c')
        return (ft_char(ap, flags, count));
    if (flags.type == 's')
        return (ft_string(ap, flags, count));
    if (flags.type == 'd' || flags.type == 'i')
        return (ft_int(ap, flags, count));
    if (flags.type == 'u')
        return (ft_unsig(ap, flags, count));
    if (flags.type  == 'x' || flags.type  == 'X')
        return (ft_hex(ap, flags, count));
    if (flags.type  == 'p')
        return (ft_pointr(ap, flags, count));
    return (count);
}