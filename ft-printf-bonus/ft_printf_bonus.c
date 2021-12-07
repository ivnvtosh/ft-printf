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

int	cheching_flag(const char **ps, t_flags *flags)
{
	int	n;

	if (**ps == '.')
	{
		flags->point = 1;
		*ps += 1;
	}
	while (*(*ps + 1) == '-')
		*ps += 1;
	n = ft_atoi(*ps);
	if (**ps == '-')
		*ps += 1;
	while (ft_isdigit(**ps) && **ps)
		*ps += 1;
	return (n);
}

void	check_flag(const char **ps, t_flags *flags)
{
	while (1)
	{
		*ps += 1;
		if (**ps == ' ')
			flags->space = 1;
		else if (**ps == '#')
			flags->hashtag = 1;
		else if (**ps == '+')
			flags->sign = '+';
		else if (**ps == '0')
			flags->fill = '0';
		else
			break ;
	}
	if (**ps == '-' || ft_isdigit(**ps))
		flags->width = cheching_flag(ps, flags);
	if (**ps == '.')
		flags->precision = cheching_flag(ps, flags);
}

int	check_format_specifier(const char **ps, char c, t_flags *flags, va_list ap)
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
		count = print_unsigned_decimal(flags, va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(flags, va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(flags, va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char(flags, '%');
	else
		return (0);
	*ps += 1;
	return (count);
}

int	format_specifier(const char **ps, t_flags *flags, va_list ap)
{
	int	count;

	check_flag(ps, flags);
	count = check_format_specifier(ps, **ps, flags, ap);
	ft_bzero(flags, sizeof(t_flags));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	t_flags	*flags;
	va_list	ap;
	int		count;

	flags = ft_calloc(1, sizeof(t_flags));
	if (flags == NULL)
		return (0);
	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			count += format_specifier(&s, flags, ap);
		else
			count += print_part(&s);
	}
	va_end(ap);
	free(flags);
	return (count);
}
