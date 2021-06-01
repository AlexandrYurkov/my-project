#include "ft_printf.h"

char *ft_width(int width)
{
    char *tmp;

    tmp = NULL;
	while (width != 0)
	{
		*tmp++ = ' ';
		width--;
	}
    return (tmp);
}