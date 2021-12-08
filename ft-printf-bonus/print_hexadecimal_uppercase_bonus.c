/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_uppercase_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:34 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:36 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

int	print_hexadecimal_uppercase(t_flag *flag, unsigned int n)
{
	int	count;
	int	nlen;

	if (flag->point && flag->precision == 0 && n == 0 && flag->width == 0)
		return (0);
	if (flag->point && flag->precision == 1 && n == 0)
		return (print_char(flag, '0'));
	if (flag->hashtag == 1 && n == 0)
		return (print_char(flag, '0'));
	if (flag->hashtag)
		flag->hashtag = 'X';
	flag->sign = 0;
	nlen = nbrlen(n, 16);
	count = getcount(flag, nlen);
	process_flag(flag, nlen);
	print_flag_nbr(flag, "0123456789ABCDEF", n);
	return (count);
}
