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
		count = print_char(flags, va_arg(ap, int));
	else if (c == 's')
		count = print_string(flags, va_arg(ap, char *));
	else if (c == 'p')
		count = print_pointer(flags, (unsigned long)va_arg(ap, void *));
	else if (c == 'd')
		count = print_decimal(flags, va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(flags, va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(flags,va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(flags, va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(flags, va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char(flags, '%');
	else
	{
		ft_bzero(flags, sizeof(o_list));
		return (0);
	}
	*ps += 1;
	return (count);
}
int	cheching_flag(char c, o_list *flags)
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->hashtag = 1;
	else if (c == '+')
		flags->sign = '+';
	else if (c == '0')
		flags->fill = '0';
	else
		return (0);
	return (1);
}

int	check_flag(const char **ps, o_list *flags, va_list ap)
{
	*ps += 1;
	while (ft_strchr(" #+0", **ps))
		*ps += cheching_flag(**ps, flags);
	if (**ps == '-' || ft_isdigit(**ps))
	{
		while (*(*ps + 1) == '-')
			*ps += 1;
		flags->width = ft_atoi(*ps);
		if (**ps == '-')
			*ps += 1;
		while (ft_isdigit(**ps) && **ps)
			*ps += 1;
	}
	if (**ps == '.')
	{
		flags->point = 1;
		*ps += 1;
		flags->precision = ft_atoi(*ps);
		while (ft_isdigit(**ps) && **ps)
			*ps += 1;
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
	free(flags);
	return (count);
}
