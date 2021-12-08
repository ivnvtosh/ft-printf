/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_lowercase_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:18 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

int	print_hexadecimal_lowercase(t_flag *flag, unsigned int n)
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
		flag->hashtag = 'x';
	flag->sign = 0;
	nlen = nbrlen(n, 16);
	count = getcount(flag, nlen);
	process_flag(flag, nlen);
	print_flag_nbr(flag, "0123456789abcdef", n);
	return (count);
}
