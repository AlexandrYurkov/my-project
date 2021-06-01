#include "ft_printf.h"

char *ft_zero(int zero)
{
    char *tmp;

    tmp = NULL;
	while (zero != 0)
	{
		*tmp++ = '0';
		zero--;
	}
    return (tmp);
}