/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:41:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:44:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_recursion(int n)
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

int	ft_is_pointer(va_list ap)
{
	int	n;
	int	count;

	n = va_arg(ap, int);
	ft_putstr_fd("0x1", 1);
	ft_recursion(n);
	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}