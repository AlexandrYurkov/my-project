#include "ft_printf.h"

int ft_width(int width)
{
	while (width != 0)
	{
		write(1, " ", 1);
		width--;
	}
	return (0);
}