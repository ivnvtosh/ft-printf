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

int	cheching_flag(const char **ps, t_flag *flag)
{
	int	n;

	if (**ps == '.')
	{
		flag->point = 1;
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

void	check_flag(const char **ps, t_flag *flag)
{
	while (1)
	{
		*ps += 1;
		if (**ps == ' ')
			flag->space = 1;
		else if (**ps == '#')
			flag->hashtag = 1;
		else if (**ps == '+')
			flag->sign = '+';
		else if (**ps == '0')
			flag->fill = '0';
		else
			break ;
	}
	if (**ps == '-' || ft_isdigit(**ps))
		flag->width = cheching_flag(ps, flag);
	if (**ps == '.')
		flag->precision = cheching_flag(ps, flag);
}

int	check_format_specifier(const char **ps, char c, t_flag *flag, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = print_char(flag, va_arg(ap, int));
	else if (c == 's')
		count = print_string(flag, va_arg(ap, char *));
	else if (c == 'p')
		count = print_pointer(flag, (unsigned long)va_arg(ap, void *));
	else if (c == 'd')
		count = print_decimal(flag, va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(flag, va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(flag, va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(flag, va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(flag, va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char(flag, '%');
	else
		return (0);
	*ps += 1;
	return (count);
}

int	format_specifier(const char **ps, t_flag *flag, va_list ap)
{
	int	count;

	check_flag(ps, flag);
	count = check_format_specifier(ps, **ps, flag, ap);
	ft_bzero(flag, sizeof(t_flag));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	t_flag	*flag;
	va_list	ap;
	int		count;

	flag = ft_calloc(1, sizeof(t_flag));
	if (flag == NULL)
		return (0);
	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			count += format_specifier(&s, flag, ap);
		else
			count += print_part(&s);
	}
	va_end(ap);
	free(flag);
	return (count);
}
