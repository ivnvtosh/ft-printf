/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:51 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	nbrlen(unsigned long n, int mode)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= mode;
		count++;
	}
	return (count);
}

void	print_sign(o_list *flags)
{
	if (flags->sign)
		ft_putchar_fd(flags->sign, 1);
}

void	print_width(o_list *flags)
{
	print_space(flags->width, flags->fill);
}

void	print_precision(o_list *flags)
{
	print_space(flags->precision, '0');
}