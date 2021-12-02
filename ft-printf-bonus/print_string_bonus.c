/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:14 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	getslen(int width, int slen)
{
	if (width > slen)
			return (width);
	return (slen);
}

void	print_precision(char *s, int precision, int slen)
{
	if (precision > slen)
		ft_putstr_fd(s, 1);
	else if (precision)
		write(1, s, precision);
	else
		ft_putstr_fd(s, 1);
}

int	ft_ft(o_list *flags, char *s, int slen)
{
	int	count;

	if (flags->width > 0)
	{
		count = getslen(flags->width, slen);
		print_space(count - slen);
		print_precision(s, flags->precision, slen);
	}
	else if (flags->width < 0)
	{
		count = getslen(flags->width * -1, slen);
		print_precision(s, flags->precision, slen);
		if (flags->precision && flags->precision < slen)
			print_space(count - flags->precision);
		else
			print_space(count - slen);
	}
	else if (flags->precision && flags->precision < slen)
	{
		count = flags->precision;
		print_precision(s, flags->precision, slen);
	}
	else
	{
		count = slen;
		print_precision(s, slen, slen);
	}
	return (count);
}

int	print_string(o_list *flags, char *s)
{
	int	count;
	int	slen;

	if (flags->point && flags->precision == 0)
		return (0);
	if (s == NULL)
		return (print_string(flags, "(null)"));
	slen = ft_strlen(s);
	count = ft_ft(flags, s, slen);
	flags->width = 0;
	flags->point = 0;
	flags->precision = 0;
	return (count);
}
