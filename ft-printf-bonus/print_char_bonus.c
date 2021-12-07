/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:53 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:58:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_char(t_flags *flags, char c)
{
	int	count;
	int	len;

	len = 1;
	if (flags->fill == 0)
		flags->fill = ' ';
	if (flags->width > 0)
	{
		count = flags->width;
		print_space(count - len, flags->fill);
		ft_putchar_fd(c, 1);
	}
	else if (flags->width < 0)
	{
		count = flags->width * -1;
		ft_putchar_fd(c, 1);
		print_space(count - len, flags->fill);
	}
	else
	{
		count = len;
		ft_putchar_fd(c, 1);
	}
	return (count);
}
