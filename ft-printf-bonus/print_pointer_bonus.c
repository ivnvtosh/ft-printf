/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:07 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_pointer(unsigned long n)
{
	ft_putstr_fd("0x", 1);
	print_number("0123456789abcdef", n, 16);
	return (nbrlen(n, 16) + 2);
}
