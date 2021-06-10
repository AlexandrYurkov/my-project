#include "ft_printf.h"

int ft_zero(int zero)
{
	while (zero != 0)
	{
		write(1, "0", 1);
		zero--;
	}
	return (0);
}