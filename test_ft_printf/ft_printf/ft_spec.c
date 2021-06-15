#include "ft_printf.h"

int ft_spec(char c, char *str)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}