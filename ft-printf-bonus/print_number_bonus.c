/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:44 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

void	print_number(char *s, unsigned long n, unsigned long mode)
{
	if (n < mode)
		ft_putchar_fd(s[n], 1);
	else
	{
		print_number(s, n / mode, mode);
		print_number(s, n % mode, mode);
	}
}
