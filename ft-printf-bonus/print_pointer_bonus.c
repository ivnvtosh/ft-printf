/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:07 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_pointer(t_flag *flag, unsigned long n)
{
	int	count;
	int	nlen;

	if (flag->point && flag->precision == 0 && n == 0 && flag->width == 0)
		return (0);
	flag->sign = 0;
	flag->hashtag = 1;
	nlen = nbrlen(n, 16);
	count = getcount(flag, nlen);
	process_flag(flag, nlen);
	print_flag_nbr(flag, "0123456789abcdef", n);
	return (count);
}
