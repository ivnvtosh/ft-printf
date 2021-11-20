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

#include "../ft_printf.h"

static void	ft_recursion(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_recursion(n / 10, fd);
		ft_recursion(n % 10, fd);
	}
}

int	ft_unsigned_decimal(va_list ap)
{
	unsigned int	n;
	int				count;

	n = va_arg(ap, unsigned int);
	ft_recursion(n, 1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}