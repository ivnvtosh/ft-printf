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
	if (n == 0)
	{
		flags->hashtag = 0;
		return (print_char('0'));
	}
	if (flags->hashtag == 1)
		ft_putstr_fd("0x", 1);
	print_number("0123456789ABCDEF", n, 16);
	if (flags->hashtag == 1)
	{
		flags->hashtag = 0;
		return (nbrlen(n, 16) + 2);
	}
	return (nbrlen(n, 16));
}
