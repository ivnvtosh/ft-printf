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

int	print_decimal(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len = print_char('-');
		n = -n;
	}
	len += nbrlen(n, 10);
	print_number("0123456789", n, 10);
	return (len);
}
