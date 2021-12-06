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

int	print_unsigned_decimal(o_list *flags, unsigned int n)
{
	int	count;

	flags->sign = 0;
	flags->hashtag = 0;
	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	count = getcount(flags, n, 10);
	process_flags(flags, n, 10);
	print_flag_nbr(flags, "0123456789", n);
	ft_bzero(flags, sizeof(o_list));
	return (count);
}
