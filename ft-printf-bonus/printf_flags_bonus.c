/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:43:48 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/07 20:43:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	print_sign(t_flag *flag)
{
	if (flag->sign)
		ft_putchar_fd(flag->sign, 1);
	else if (flag->space)
		ft_putchar_fd(' ', 1);
	else if (flag->hashtag == 2)
		ft_putstr_fd("0X", 1);
	else if (flag->hashtag)
		ft_putstr_fd("0x", 1);
}

void	print_width(t_flag *flag)
{
	print_nchar(flag->fill, flag->width);
}

void	print_precision(t_flag *flag)
{
	print_nchar('0', flag->precision);
}
