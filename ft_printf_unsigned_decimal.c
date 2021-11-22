/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:57:21 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:59:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursion(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + 48, 1);
	else
	{
		ft_recursion(n / 10);
		ft_recursion(n % 10);
	}
}

static int	ft_nbrlen(unsigned int n)
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

int	ft_unsigned_decimal(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	ft_recursion(n);
	return (ft_nbrlen(n));
}