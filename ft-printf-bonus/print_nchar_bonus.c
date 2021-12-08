/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nchar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:34:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/01 19:34:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

void	print_nchar(char c, int len)
{
	while (len > 0)
	{
		ft_putchar_fd(c, 1);
		len--;
	}
}
