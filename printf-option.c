/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:22:33 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/27 14:22:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_justify(int count, char c)
{
	int	len;

	len = 0;
	while (count > 0)
	{
		ft_putchar_fd(c, 1);
		count--;
		len++;
	}
	return (len);
}