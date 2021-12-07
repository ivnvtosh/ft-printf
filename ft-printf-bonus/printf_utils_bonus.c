/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:51 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	nbrlen(unsigned long n, int mode)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= mode;
		count++;
	}
	return (count);
}

void	print_sign(o_list *flags)
{
	if (flags->sign)
		ft_putchar_fd(flags->sign, 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	else if (flags->hashtag == 2)
		ft_putstr_fd("0X", 1);
	else if (flags->hashtag)
		ft_putstr_fd("0x", 1);
}

void	print_width(o_list *flags)
{
	print_space(flags->width, flags->fill);
}

void	print_precision(o_list *flags)
{
	print_space(flags->precision, '0');
}

int	getcount(o_list *flags, unsigned long n, int mode)
{
	int	count;
	int	nlen;
	int	width;

	width = flags->width;
	nlen = nbrlen(n, mode);
	if (flags->hashtag)
		nlen += 2;
	if (width < 0)
		width = -width;
	if (flags->precision > nlen && flags->precision >= width)
		count = flags->precision;
	else if (width > nlen)
		return (width);
	else
		count = nlen;
	if (flags->sign)
		count++;
	if (flags->space && flags->sign == 0)
		count++;
	return (count);
}

void	print_flag_nbr(o_list *flags, char *s, unsigned long n)
{
	if (n == 0 && flags->point && flags->precision == 0)
		variant_1(flags);
	else if (flags->width > 0 && flags->fill == '0')
		variant_2(flags, s, n);
	else if (flags->width > 0)
		variant_3(flags, s, n);
	else if (flags->width < 0)
		variant_4(flags, s, n);
	else
		variant_5(flags, s, n);
}
