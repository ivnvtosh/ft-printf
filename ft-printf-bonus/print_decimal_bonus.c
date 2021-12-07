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

int	print_decimal(t_flags *flags, long n)
{
	int	count;

	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	if (flags->point && flags->precision == 1 && n == 0)
		return (print_char(flags, '0'));
	if (n < 0)
	{
		flags->sign = '-';
		n = -n;
	}
	flags->hashtag = 0;
	count = getcount(flags, n, 10);
	process_flags(flags, n, 10);
	print_flag_nbr(flags, "0123456789", n);
	return (count);
}
