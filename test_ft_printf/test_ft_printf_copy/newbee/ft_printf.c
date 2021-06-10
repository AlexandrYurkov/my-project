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
	free((char *)tmp);
	return (count);
}

int main(void)
{
	/*
	TEST(9, print(" *%-*.*x* *%*.*x* ", 4, 5, 10, 10, 21, -10));
	TEST(10, print(" *%-*.*x* *%*.*x* ", 6, 2, 102, 10, 21, -101));
	TEST(11, print(" *%*.*x* *%*.*x* ", -6, 2, 102, 10, 21, 101));
	TEST(12, print(" 0*%0-*.*x*0 0*%0*.*x*0 ", 6, 2, 102, 10, 21, -101));
	TEST(13, print(" 0*%0-*.*x*0 0*%0*.*x*0 ", 2, 6, 102, 21, 10, -101));
	print(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, INT_MAX, 21, INT_MIN));
	print(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));*/
	
	/*printf("%d\n", printf("2printf: | --0*%0*.0u*0 0*%0*.10u*0-- |\n",-21, INT_MAX, 21, INT_MIN));
	printf("%d\n", ft_printf("2my_pri: | --0*%0*.0u*0 0*%0*.10u*0-- |\n", -21, INT_MAX, 21, INT_MIN));*/

	printf("%d\n", printf("2printf: | 0*%0-*.*x*0 0*%0*.*x*0 |\n", 2, 6, 102, 21, 10, -101));
	printf("%d\n", ft_printf("2my_pri: | 0*%0-*.*x*0 0*%0*.*x*0 |\n", 2, 6, 102, 21, 10, -101));


	/*printf("%d\n", printf("3printf: | --0*%-0*.4d*0 0*%-0*.4d*0-- |\n", -21, CHAR_MAX, 21, CHAR_MIN));
	printf("%d\n", ft_printf("3my_pri: | --0*%-0*.4d*0 0*%-0*.4d*0-- |\n", -21, CHAR_MAX, 21, CHAR_MIN));

	printf("%d\n", printf("3printf: | --0*%0*.0d*0 0*%0*.10d*0-- |\n", -21, LONG_MAX, 21, LONG_MIN));
	printf("%d\n", ft_printf("3my_pri: | --0*%0*.0d*0 0*%0*.10d*0-- |\n", -21, LONG_MAX, 21, LONG_MIN));

	printf("%d\n", printf("4printf: | --0*%-0*.20d*0 0*%-0*.10d*0-- |\n", -21, CHAR_MAX, 21, CHAR_MIN));
	printf("%d\n", ft_printf("4my_pri: | --0*%-0*.20d*0 0*%-0*.10d*0-- |\n", -21, CHAR_MAX, 21, CHAR_MIN));*/

	return 0;
}