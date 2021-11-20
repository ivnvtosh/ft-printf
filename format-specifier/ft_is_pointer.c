/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:42:56 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/20 19:42:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_recursion(unsigned long long n)
{
	if (n < 10)
		ft_putchar_fd(n + 48, 1);
	else if (n < 16)
		ft_putchar_fd(n + 87, 1);
	else
	{
		ft_recursion(n / 16);
		ft_recursion(n % 16);
	}
}

static int	ft_nbrlen(unsigned long long n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_is_pointer(va_list ap)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	ft_putstr_fd("0x", 1);
	ft_recursion(n);
	return (ft_nbrlen(n));
}
