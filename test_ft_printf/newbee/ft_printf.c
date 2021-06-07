#include "ft_printf.h"

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
	free((char *)tmp);
	return (count);
}

int main()
{
	char *s_hidden = "hi low";
	ft_printf("%.09s", s_hidden);
	return (0);
}