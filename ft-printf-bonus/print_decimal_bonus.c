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

int	print_decimal(t_flag *flag, long n)
{
	int	count;
	int	nlen;

	if (flag->point && flag->precision == 0 && n == 0 && flag->width == 0)
		return (0);
	if (flag->point && flag->precision == 1 && n == 0)
		return (print_char(flag, '0'));
	if (n < 0)
	{
		flag->sign = '-';
		n = -n;
	}
	flag->hashtag = 0;
	nlen = nbrlen(n, 10);
	count = getcount(flag, nlen);
	process_flag(flag, nlen);
	print_flag_nbr(flag, "0123456789", n);
	return (count);
}
