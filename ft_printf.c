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
#include "libft/libft.h"

int	format_specifier(const char **s, char c, va_list ap, o_list *list)
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
		count = print_decimal(list, va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(list, va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char('%');
	else
		return (0);
	*s += 1;
	return (count);
}

const char	*check_it_out(const char *s, o_list *list)
{
	if (*s == ' ')
		list->space = 1;
	else if (*s == '+')
		list->sign = 1;
	else if (*s == '0')
		list->ch = '0';
	return (++s);
}

int	check_option(const char **ps, va_list ap, o_list *list)
{
	*ps += 1;
	while (ft_strchr("0+ -", **ps))
		*ps = check_it_out(*ps, list);
	list->count = ft_atoi(*ps);
	if (**ps == '-')
		*ps += 1;
	while (ft_isdigit(**ps))
		*ps += 1;
	return (format_specifier(ps, **ps, ap, list));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	o_list	*list;
	int		count;

	va_start(ap, s);
	list = (o_list *)malloc(sizeof(o_list));
	list->space = 0;
	list->sign = 0;
	list->ch = 32;
	count = 0;
	while (*s != '\0')
	{
		if (*s != '%')
			count += print_char(*s++);
		else
			count += check_option(&s, ap, list);
	}
	va_end(ap);
	free(list);
	return (count);
}
