/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_uppercase_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:34 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:36 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_hexadecimal_uppercase(o_list *flags, unsigned int n)
{
	int	count;

	flags->sign = 0;
	if (flags->point && flags->precision == 0 && n == 0 && flags->width == 0)
		return (0);
	if (flags->hashtag == 1 && n == 0)
	{
		ft_bzero(flags, sizeof(o_list));
		return (print_char(flags, '0'));
	}
	if (flags->hashtag)
		flags->hashtag = 2;
	count = getcount(flags, n, 16);
	process_flags(flags, n, 16);
	print_flag_nbr(flags, "0123456789ABCDEF", n);
	ft_bzero(flags, sizeof(o_list));
	return (count);
}
