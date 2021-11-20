/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:00 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:23:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isformat_specifier(const char *s, va_list ap)
{
	int	count;

	if (*s == 'c')
		count = ft_is_char(ap);
	else if (*s == 's')
		count = ft_is_string(ap);
	else if (*s == 'p')
		count = ft_is_pointer(ap);
	else if (*s == 'd')
		count = ft_is_decimal(ap);
	else if (*s == 'i')
		count = ft_is_decimal(ap);
	else if (*s == 'u')
		count = ft_unsigned_decimal(ap);
	else if (*s == 'x')
		count = ft_is_hexadecimal(ap);
	else if (*s == 'X')
		count = ft_is_hexadecimal_X(ap);
	else if (*s == '%')
		count = ft_is_0lo('%', 1);
	else
		return (0);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i] != '\0')
			ft_putchar_fd(s[i++], 1);
		count += i;
		if (s[i] == '%')
		{
			count += ft_isformat_specifier(&s[i + 1], ap);
			i += 2;
		}
	}
	va_end(ap);
	return (count);
}
