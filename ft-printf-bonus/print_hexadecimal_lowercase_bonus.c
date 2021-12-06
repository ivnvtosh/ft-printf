/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_lowercase_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:18 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static int	getcount(o_list *flags, unsigned int n)
{
	int	count;
	int	nlen;
	int	width;

	width = flags->width;
	nlen = nbrlen(n, 16);
	if (width < 0)
		width = -width;
	if (flags->precision >= width && flags->precision > nlen)
		count = flags->precision + (flags->sign != 0);
	else if (width > nlen)
		count = width;
	else
		count = nlen + (flags->sign != 0);
	return (count);
}

static void	kek(o_list *flags, unsigned int n)
{
	int	nlen;
	int	width;

	nlen = nbrlen(n, 16);
	if (flags->fill == 0 || flags->precision)
		flags->fill = ' ';
	if (flags->width > nlen && flags->width > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width = flags->width - flags->precision - (flags->sign != 0);
		else
			flags->width = flags->width - nlen - (flags->sign != 0);
	}
	else if (flags->width * -1 > nlen && flags->width * -1 > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width = flags->width + flags->precision + (flags->sign != 0);
		else
			flags->width = flags->width + nlen + (flags->sign != 0);
	}
	else
		flags->width = 0;
	if (flags->precision > nlen)
		flags->precision = flags->precision - nlen;
	else
		flags->precision = 0;
}

static void	print_flag_nbr(o_list *flags, char *s, unsigned int n)
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

int	print_hexadecimal_lowercase(o_list *flags, unsigned int n)
{
	int	count;

	count = getcount(flags, n);
	kek(flags, n);
	print_flag_nbr(flags, "0123456789abcdef", n);
	ft_bzero(flags, sizeof(o_list));
	return (count);
}

// int	print_hexadecimal_lowercase(o_list *flags, unsigned int n)
// {
// 	if (flags->hashtag == 1)
// 	{
// 		flags->hashtag = 0;
// 		if (n == 0)
// 			return (print_char(flags, '0'));
// 		ft_putstr_fd("0x", 1);
// 		print_number("0123456789abcdef", n, 16);
// 		return (nbrlen(n, 16) + 2);
// 	}
// 	print_number("0123456789abcdef", n, 16);
// 	return (nbrlen(n, 16));
// }
