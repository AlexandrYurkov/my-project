#include "ft_printf.h"

int	ft_strcat (char *dst, char *src)
{
	int	DST;
	int	count;

	DST = ft_strlen(dst);
	count = 0;
	while (src[count])
	{
		dst[DST] = src[count];
		count++;
		DST++;
	}
	dst[DST] = '\0';
	return (count);
}
