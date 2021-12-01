/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:34:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/01 19:34:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_space(int count)
{
	int	len;

	len = count;
	while (count)
	{
		ft_putchar_fd(' ', 1);
		count--;
	}
	return (len);
}
