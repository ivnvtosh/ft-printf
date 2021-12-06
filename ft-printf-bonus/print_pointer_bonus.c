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
	int	nlen;
	int	count;

	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	flags->hashtag = 1;
	flags->fill = ' ';
	nlen = nbrlen(n, 16) + 2;
	if (flags->width > nlen)
	{
		count = flags->width;
		flags->width -= nlen;
		variant_3(flags, "0123456789abcdef", n);
	}
	else if (flags->width * -1 > nlen)
	{
		count = flags->width * -1;
		flags->width += nlen;
		variant_4(flags, "0123456789abcdef", n);
	}
	else
	{
		count = nlen;
		flags->width = 0;
		variant_5(flags, "0123456789abcdef", n);
	}
	ft_bzero(flags, sizeof(o_list));
	return (count);
}
