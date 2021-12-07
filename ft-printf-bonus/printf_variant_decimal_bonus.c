/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_variant_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:43:08 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/04 20:43:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	variant_1(t_flags *flags)
{
	if (flags->width < 0)
		flags->width = -flags->width;
	flags->width += 1;
	flags->fill = ' ';
	print_width(flags);
}

void	variant_2(t_flags *flags, char *s, unsigned long n)
{
	print_sign(flags);
	print_width(flags);
	print_precision(flags);
	print_number(s, n, ft_strlen(s));
}

void	variant_3(t_flags *flags, char *s, unsigned long n)
{
	print_width(flags);
	print_sign(flags);
	print_precision(flags);
	print_number(s, n, ft_strlen(s));
}

void	variant_4(t_flags *flags, char *s, unsigned long n)
{
	flags->width = -flags->width;
	print_sign(flags);
	print_precision(flags);
	print_number(s, n, ft_strlen(s));
	print_width(flags);
}

void	variant_5(t_flags *flags, char *s, unsigned long n)
{
	print_sign(flags);
	print_precision(flags);
	print_number(s, n, ft_strlen(s));
}
