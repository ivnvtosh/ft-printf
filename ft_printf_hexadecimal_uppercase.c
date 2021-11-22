/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hexadecimal_uppercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:13:24 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 21:15:19 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursion(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + 48, 1);
	else if (n < 16)
		ft_putchar_fd(n + 55, 1);
	else
	{
		ft_recursion(n / 16);
		ft_recursion(n % 16);
	}
}

static int	ft_nbrlen(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_is_hexadecimal_uppercase(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	ft_recursion(n);
	return (ft_nbrlen(n));
}