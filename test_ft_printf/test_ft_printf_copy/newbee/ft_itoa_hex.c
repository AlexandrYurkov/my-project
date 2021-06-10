#include "ft_printf.h"

static int ft_size(unsigned long long n)
{
	int i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char *ft_itoa_hex(unsigned long long n, t_flags flags)
{
	char *str;
	int size;
	int module;
	int convert;

	if (flags.type == 'X')
		convert = 55;
	else
		convert = 87;
	size = ft_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (n > 0)
	{
		module = n % 16;
		if (module > 9)
			str[size] = module + convert;
		else
			str[size] = module + '0';
		n = n / 16;
		size--;
	}
	return (str);
}