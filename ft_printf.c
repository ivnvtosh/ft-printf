/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:21:46 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 14:21:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(const char **s, char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = print_char(va_arg(ap, int));
	else if (c == 's')
		count = print_string(va_arg(ap, char *));
	else if (c == 'p')
		count = print_pointer(va_arg(ap, unsigned long int));
	else if (c == 'd')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char('%');
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
			count += print_char(*s++);
		else
			count += format_specifier(&s, *(s + 1), ap);
	}
	va_end(ap);
	return (count);
}
