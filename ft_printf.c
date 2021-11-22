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

int	ft_isformat_specifier(const char **s, char c, va_list ap)
{
	int	count;

	count = 0;
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
		*s -= 1;
	*s += 2;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s != '\0')
	{
		if (*s != '%')
			count += ft_put(*s++);
		else
			count += ft_isformat_specifier(&s, *(s + 1), ap);
	}
	va_end(ap);
	return (count);
}

