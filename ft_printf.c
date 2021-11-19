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

int	ft_isformat_specifier(const char **s, va_list ap)
{
	const char	*ss;
	int			count;

	count = 0;
	ss = *s;
	if (*(ss + 1) == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		*s += 2;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	while (*s)
	{
		while (*s != '%' && *s != '\0')
			ft_putchar_fd(*s++, 1);
		if (*s == '%')
			ft_isformat_specifier(&s, ap);
	}
	va_end(ap);
	return (1);
}
