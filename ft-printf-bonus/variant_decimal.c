/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variant_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:43:08 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/04 20:43:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	variant_1(o_list *flags)
{
	if (flags->width < 0)
		flags->width = -flags->width;
	flags->width += 1;
	flags->fill = ' ';
	print_width(flags);
}

void	variant_2(o_list *flags, unsigned int n)
{
	print_sign(flags);
	print_width(flags);
	print_precision(flags);
	print_number("0123456789", n, 10);
}

void	variant_3(o_list *flags, unsigned int n)
{
	print_width(flags);
	print_sign(flags);
	print_precision(flags);
	print_number("0123456789", n, 10);
}

void	variant_4(o_list *flags, unsigned int n)
{
	flags->width = -flags->width;
	print_sign(flags);
	print_precision(flags);
	print_number("0123456789", n, 10);
	print_width(flags);
}

void	variant_5(o_list *flags, unsigned int n)
{
	print_sign(flags);
	print_precision(flags);
	print_number("0123456789", n, 10);
}