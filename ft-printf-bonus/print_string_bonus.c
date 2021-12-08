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

static int	getslen(t_flag *flag, int width, int slen)
{
	if (width > slen || (flag->precision && flag->precision < slen))
		return (width);
	return (slen);
}

static void	print_precision_str(char *s, int precision, int slen)
{
	if (precision > slen)
		ft_putstr_fd(s, 1);
	else if (precision)
		write(1, s, precision);
	else
		ft_putstr_fd(s, 1);
}

static int	variant_string(t_flag *flag, char *s, int slen)
{
	int	count;

	count = getslen(flag, flag->width, slen);
	if (flag->precision && flag->precision < slen)
		print_nchar(' ', count - flag->precision);
	else
		print_nchar(' ', count - slen);
	print_precision_str(s, flag->precision, slen);
	return (count);
}

int	ft_ft(t_flag *flag, char *s, int slen)
{
	int	count;

	if (flag->width > 0)
		count = variant_string(flag, s, slen);
	else if (flag->width < 0)
	{
		count = getslen(flag, flag->width * -1, slen);
		print_precision_str(s, flag->precision, slen);
		if (flag->precision && flag->precision < slen)
			print_nchar(' ', count - flag->precision);
		else
			print_nchar(' ', count - slen);
	}
	else if (flag->precision && flag->precision < slen)
	{
		count = flag->precision;
		print_precision_str(s, flag->precision, slen);
	}
	else
	{
		count = slen;
		print_precision_str(s, slen, slen);
	}
	return (count);
}

int	print_string(t_flag *flag, char *s)
{
	int	count;
	int	slen;

	if (flag->point && flag->precision == 0)
	{
		if (flag->width > 0)
			print_nchar(' ', flag->width);
		if (flag->width < 0)
			print_nchar(' ', -flag->width);
		return (flag->width);
	}
	if (s == NULL)
		return (print_string(flag, "(null)"));
	slen = ft_strlen(s);
	count = ft_ft(flag, s, slen);
	return (count);
}
