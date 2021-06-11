#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *c, ...)
{
	va_list ap;
	int count;
	const char *tmp;

	count = 0;
	if (!c)
		return 0;
	if (!(tmp = ft_strdup(c)))
		return (0);
	va_start(ap, c);
	count = ft_parse(tmp, ap);
	va_end(ap);
	if (tmp)
	free((char *)tmp);
	return (count);
}

int main(void)
{
	printf("%d\n", printf("2printf: |ultimate2 %*d %*s %*X %*i %*u|\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10, -55, 1, -60));
	printf("%d\n", ft_printf("2my_pri: |ultimate2 %*d %*s %*x %*X %*i %*u|\n",  1, 5000, 1, "hey", 10, 54700, 1, 300, 10, -55, 1, -60));

	return 0;
}