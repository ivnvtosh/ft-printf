/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:43:48 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/07 20:43:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	print_sign(t_flags *flags)
{
	if (flags->sign)
		ft_putchar_fd(flags->sign, 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	else if (flags->hashtag == 2)
		ft_putstr_fd("0X", 1);
	else if (flags->hashtag)
		ft_putstr_fd("0x", 1);
}

void	print_width(t_flags *flags)
{
	print_space(flags->width, flags->fill);
}

void	print_precision(t_flags *flags)
{
	print_space(flags->precision, '0');
}
