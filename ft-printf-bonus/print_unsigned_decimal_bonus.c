/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:23 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:24 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_unsigned_decimal(t_flags *flags, unsigned int n)
{
	int	count;
	int	nlen;

	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	if (flags->point && flags->precision == 1 && n == 0)
		return (print_char(flags, '0'));
	flags->sign = 0;
	flags->hashtag = 0;
	nlen = nbrlen(n, 10);
	count = getcount(flags, nlen);
	process_flags(flags, nlen);
	print_flag_nbr(flags, "0123456789", n);
	return (count);
}
