#include "ft_printf.h"


t_flags init_flags(void)
{
t_flags flags;

flags.flag_minus = 0;
flags.flag_zero = 0;
flags.dot = -1;
flags.type = 0;
flags.width = 0;
flags.space = 0;

return (flags);
}

int ft_printf(const char *c, ...)
{
	va_list ap;
	t_flags *flags;
	int i;
	char *tmp;

	flags = NULL;
	if(!c)
		return 0;
	i = 0;
	va_start(ap, c);
	if(!(tmp = ft_strdup(c)))
		return (-1);
	while (tmp[i])
	{
		ft_flags(tmp, ap, i, flags);
		i++;
	}
	va_end(ap);
	free ((char *)tmp);
	return (i);
}
