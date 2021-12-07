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

int	print_pointer(o_list *flags, unsigned long n)
{
	int	count;

	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	flags->sign = 0;
	flags->hashtag = 1;
	count = getcount(flags, n, 16);
	process_flags(flags, n, 16);
	print_flag_nbr(flags, "0123456789abcdef", n);
	return (count);
}
