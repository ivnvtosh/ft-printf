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

#include "../ft_printf.h"

int	ft_is_decimal(va_list ap)
{
	int	n;
	int	count;

	n = va_arg(ap, int);
	ft_putnbr_fd(n, 1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}