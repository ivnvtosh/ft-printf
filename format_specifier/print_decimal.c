/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:00:30 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:00:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static int	ft_nbrlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	else
		count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	print_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}
