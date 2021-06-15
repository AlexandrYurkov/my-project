/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:28:42 by lfallon           #+#    #+#             */
/*   Updated: 2021/06/15 21:31:13 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_one(char c, int count, t_flags flags)
{
	write(1, &c, 1);
	ft_width((flags.width) - 1);
	count += flags.width;
	return (count);
}

static int	get_two(char c, int count, t_flags flags)
{
	ft_zero((flags.width) - 1);
	write(1, &c, 1);
	count += flags.width;
	return (count);
}

static int	get_free(char c, int count, t_flags flags)
{
	ft_width((flags.width) - 1);
	write(1, &c, 1);
	count += flags.width;
	return (count);
}

int	ft_char(va_list ap, t_flags flags, int count)
{
	char	c;

	if (flags.type == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	if (flags.width <= 1)
	{
		write(1, &c, 1);
		count += 1;
	}
	if (flags.width > 1 && (flags.minus == 1 || flags.p_star == 1))
		count = get_one(c, count, flags);
	if (flags.minus == 0 && flags.width > 1 && c == '%' && flags.zero == 1)
		count = get_two(c, count, flags);
	if (flags.width > 1 && flags.minus == 0
		&& flags.zero == 0 && flags.p_star == 0)
		count = get_free(c, count, flags);
	return (count);
}
