/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:02 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static int	getslen(int width, int precision, int sign, int nlen)
{
	int	count;

	if (width < 0)
		width = -width;
	if (precision > width)
		count = precision;
	else if (width > nlen)
		count = width;
	else
		count = nlen;
	if (sign)
		count++;
	return (count);
}

static void	width(o_list *flags, int width, int nlen, int count)
{
	if (flags->precision > width)
		return ;
	else if (precision > nlen)
		print_space(count - flags->precision - (flags->sign != 0) * 2, ' ');
	else
		print_space(count - nlen - (flags->sign != 0) * 2, ' ');
}

void	variant_1(o_list *flags, unsigned int n)
{
	width(flags, flags->width, nlen, count);
	if (flags->sign)
		ft_putchar_fd(sign, 1);
	if (flags->precision > nlen)
		print_space(flags->precision - nlen, '0');
	print_number("0123456789", n, 10);
}

void	variant_2(o_list *flags, unsigned int n)
{
	if (flags->sign)
		ft_putchar_fd(sign, 1);
	if (flags->precision > nlen)
			print_space(flags->precision - nlen, '0');
	print_number("0123456789", n, 10);
	width(flags, flags->width * -1, nlen, count);
}

void	variant_3(o_list *flags, unsigned int n)
{
	if (flags->sign)
		ft_putchar_fd(sign, 1);
	if (flags->precision > nlen)
			print_space(flags->precision - nlen, '0');
	print_number("0123456789", n, 10);
}

int	print_flag_nbr(o_list *flags, unsigned int n)
{
	int	nlen;
	int	count;

	nlen = nbrlen(n, 10);
	count = getslen(flags->width, flags->precision, flags->sign, nlen);
	if (flags->width > 0)
		variant_1(flags, n);
	else if (flags->width < 0)
		variant_2(flags, n);
	else
		variant_3(flags, n);
	return (count);
}

int	print_decimal(o_list *flags, long n)
{
	int	count;
	
	if (n < 0)
	{
		flags->sign = '-';
		n = -n;
	}
	print_flag_nbr(flags, n);
	ft_bzero(flags, sizeof(o_list));
	return (count);
}

// static int	getslen(int width, int precision, int sign, int nlen)
// {
// 	int	count;

// 	if (width < 0)
// 		width = -width;
// 	if (precision > width)
// 		count = precision;
// 	else if (width > nlen)
// 		count = width;
// 	else
// 		count = nlen;
// 	if (sign)
// 		count++;
// 	return (count);
// }

// static void	width(o_list *flags, int width, int nlen, int count)
// {
// 	int	sign;
// 	int	precision;

// 	sign = flags->sign;
// 	precision = flags->precision;
// 	if (precision > width)
// 		return ;
// 	else if (precision > nlen)
// 		print_space(count - precision - (sign != 0) * 2, ' ');
// 	else
// 		print_space(count - nlen - (sign != 0) * 2, ' ');
// }

// static void	precision(o_list *flags, int n, int nlen)
// {
// 	if (flags->precision > nlen)
// 			print_space(flags->precision - nlen, '0');
// 	print_number("0123456789", n, 10);
// }

// static void	sign(int sign)
// {
// 	if (sign)
// 		ft_putchar_fd(sign, 1);
// }

// void	zero(o_list *flags)
// {
// 	char	*s;
// 	int		i;

// 	s = (char *)flags;
// 	i = sizeof(o_list);
// 	while (i)
// 		s[--i] = 0;
// }

// int	print_flag_nbr(o_list *flags, unsigned int n)
// {
// 	int	nlen;
// 	int	count;

// 	nlen = nbrlen(n, 10);
// 	count = getslen(flags->width, flags->precision, flags->sign, nlen);
// 	if (flags->width > 0)
// 	{
// 		width(flags, flags->width, nlen, count);
// 		sign(flags->sign);
// 		precision(flags, n, nlen);
// 	}
// 	else if (flags->width < 0)
// 	{
// 		sign(flags->sign);
// 		precision(flags, n, nlen);
// 		width(flags, flags->width * -1, nlen, count);
// 	}
// 	else
// 	{
// 		sign(flags->sign);
// 		precision(flags, n, nlen);
// 	}
// 	return (count);
// }

// int	print_decimal(o_list *flags, long n)
// {
// 	int	count;
	
// 	if (n < 0)
// 	{
// 		flags->sign = '-';
// 		n = -n;
// 	}
// 	print_flag_nbr(flags, n);
// 	zero(flags);
// 	return (count);
// }

// static int	getslen(int width, int precision, int nlen)
// {
// 	if (precision > width)
// 		return (precision);
// 	if (width > nlen)
// 		return (width);
// 	return (nlen);
// }

// static void	print_precision(int n, int precision, int nlen)
// {
// 	if (precision > nlen)
// 		print_space(precision - nlen, '0');
// 	print_number("0123456789", n, 10);
// }

// static void	width(int width, int precision, int nlen, int count)
// {
// 	if (precision > width)
// 		return ;
// 	else if (precision > nlen)
// 		print_space(count - precision, ' ');
// 	else
// 		print_space(count - nlen, ' ');
// }


// static int	precision(o_list *flags, int n, int nlen, int count)
// {
// 	if (flags->precision && flags->precision < nlen)
// 	{
// 		count = flags->precision;
// 		print_precision(n, flags->precision, nlen);
// 	}
// 	else
// 	{
// 		count = nlen;
// 		print_precision(n, flags->precision, nlen);
// 	}
// 	return (count);
// }

// int	print_decimal(o_list *flags, long n)
// {
// 	int	count;
// 	int	nlen;

// 	nlen = nbrlen(n, 10);
// 	if (flags->width > 0)
// 	{
// 		count = getslen(flags->width, flags->precision, nlen);
// 		width(flags->width, flags->precision, nlen, count);
// 		count = precision(flags, n, nlen, count);
// 	}
// 	else if (flags->width < 0)
// 	{
// 		count = getslen(flags->width * -1, flags->precision, nlen);
// 		count = precision(flags, n, nlen, count);
// 		width(flags->width * -1, flags->precision, nlen, count);
// 	}
// 	else
// 		count = precision(flags, n, nlen, count);
// 	return (count);
// }
