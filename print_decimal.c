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

#include "ft_printf.h"
#include "libft/libft.h"

int	print_decimal(int n)
{
	int				len;
	unsigned int	u;

	len = nbrlen(u, 10);
	if (n < 0)
	{
		len += print_char('-');
		u = -n;
	}
	else
		u = n;
	print_number("0123456789", u, 10);
	return (len);
}
