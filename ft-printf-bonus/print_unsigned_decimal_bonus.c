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
#include "../libft/libft.h"

int	print_unsigned_decimal(t_flag *flag, unsigned int n)
{
	int	count;
	int	nlen;

	if (flag->point && flag->precision == 0 && n == 0 && flag->width == 0)
		return (0);
	if (flag->point && flag->precision == 1 && n == 0)
		return (print_char(flag, '0'));
	flag->sign = 0;
	flag->hashtag = 0;
	nlen = nbrlen(n, 10);
	count = getcount(flag, nlen);
	process_flag(flag, nlen);
	print_flag_nbr(flag, "0123456789", n);
	return (count);
}
