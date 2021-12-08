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
#include "../libft/libft.h"

int	print_char(t_flag *flag, char c)
{
	int	count;
	int	len;

	len = 1;
	if (flag->fill == 0)
		flag->fill = ' ';
	if (flag->width > 0)
	{
		count = flag->width;
		print_nchar(flag->fill, count - len);
		ft_putchar_fd(c, 1);
	}
	else if (flag->width < 0)
	{
		count = flag->width * -1;
		ft_putchar_fd(c, 1);
		print_nchar(flag->fill, count - len);
	}
	else
	{
		count = len;
		ft_putchar_fd(c, 1);
	}
	return (count);
}
