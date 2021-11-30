/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:58:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	format_specifier(const char **ps, char c, o_list *flags, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = print_char(va_arg(ap, int));
	else if (c == 's')
		count = print_string(va_arg(ap, char *));
	else if (c == 'p')
		count = print_pointer((unsigned long)va_arg(ap, void *));
	else if (c == 'd')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(flags, va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(flags, va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char('%');
	else
		*ps -= 1;
	*ps += 1;
	return (count);
}

int	check_flag(const char **ps, o_list *flags, va_list ap)
{
	*ps += 1;
	if (**ps == '#')
	{
		*ps += 1;
		flags->hashtag = 1;
	}
	return (format_specifier(ps, **ps, flags, ap));
}

int	ft_printf(const char *s, ...)
{
	o_list	*flags;
	va_list	ap;
	int		count;

	flags = ft_calloc(1, sizeof(o_list));
	if (flags == NULL)
		return (0);
	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			count += check_flag(&s, flags, ap);
		else
			count += print_part(&s);
	}
	va_end(ap);
	return (count);
}
