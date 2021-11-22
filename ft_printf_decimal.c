/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:41:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:44:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if(n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_is_decimal(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}

