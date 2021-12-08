/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:51 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	nbrlen(unsigned long n, int mode)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= mode;
		count++;
	}
	return (count);
}

int	getcount(t_flag *flag, int nlen)
{
	int	count;
	int	width;

	width = flag->width;
	if (flag->hashtag)
		nlen += 2;
	if (width < 0)
		width = -width;
	if (flag->precision > nlen && flag->precision >= width)
		count = flag->precision;
	else if (width > nlen)
		return (width);
	else
		count = nlen;
	if (flag->sign)
		count++;
	if (flag->space && flag->sign == 0)
		count++;
	return (count);
}

void	print_flag_nbr(t_flag *flag, char *s, unsigned long n)
{
	if (n == 0 && flag->point && flag->precision == 0)
		variant_1(flag);
	else if (flag->width > 0 && flag->fill == '0')
		variant_2(flag, s, n);
	else if (flag->width > 0)
		variant_3(flag, s, n);
	else if (flag->width < 0)
		variant_4(flag, s, n);
	else
		variant_5(flag, s, n);
}
