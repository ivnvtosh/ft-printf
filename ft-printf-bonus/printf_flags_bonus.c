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
#include "../libft/libft.h"

void	print_flag(t_flag *flag)
{
	if (flag->sign)
		ft_putchar_fd(flag->sign, 1);
	else if (flag->space)
		ft_putchar_fd(' ', 1);
	else if (flag->hashtag == 'X')
		ft_putstr_fd("0X", 1);
	else if (flag->hashtag == 'x')
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
