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

int	ft_put(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_isformat_specifier(char c, va_list ap)
{
	int	count;

	if (c == 'c')
		count = ft_is_char(ap);
	else if (c == 's')
		count = ft_is_string(ap);
	else if (c == 'p')
		count = ft_is_pointer(ap);
	else if (c == 'd')
		count = ft_is_decimal(ap);
	else if (c == 'i')
		count = ft_is_decimal(ap);
	else if (c == 'u')
		count = ft_unsigned_decimal(ap);
	else if (c == 'x')
		count = ft_is_hexadecimal_lowercase(ap);
	else if (c == 'X')
		count = ft_is_hexadecimal_uppercase(ap);
	else if (c == '%')
		count = ft_put('%');
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
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			count += ft_put(s[i++]);
		else
		{
			count += ft_isformat_specifier(s[++i], ap);
			i += 2;
		}
	}
	va_end(ap);
	return (count);
}
