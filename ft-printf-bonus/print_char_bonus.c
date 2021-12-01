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

int	print_char(o_list *flags, char c)
{
	int	len;

	len = 1;
	if (flags->width > 0)
	{
		len = flags->width;
		print_space(len - 1);
		ft_putchar_fd(c, 1);
		flags->width = 0;
	}
	else if (flags->width < 0)
	{
		len = flags->width * -1;
		ft_putchar_fd(c, 1);
		print_space(len - 1);
		flags->width = 0;
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}
