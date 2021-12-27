/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_process_flag_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:31:27 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/07 20:31:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

static void	process_fill(t_flag *flag)
{
	if (flag->fill == 0 || flag->precision)
		flag->fill = ' ';
}

static void	process_width(t_flag *flag, int nlen)
{
	if (flag->hashtag)
		nlen += 2;
	if (flag->width > nlen && flag->width > flag->precision)
	{
		if (flag->precision > nlen)
			flag->width -= flag->precision;
		else
			flag->width -= nlen;
	}
	else if (flag->width * -1 > nlen && flag->width * -1 > flag->precision)
	{
		if (flag->precision > nlen)
			flag->width += flag->precision;
		else
			flag->width += nlen;
	}
	else
		flag->width = 0;
	if (flag->width > 0 && (flag->sign || flag->space))
		flag->width -= 1;
	if (flag->width < 0 && (flag->sign || flag->space))
		flag->width += 1;
}

static void	process_precision(t_flag *flag, int nlen)
{
	if (flag->precision > nlen)
		flag->precision = flag->precision - nlen;
	else
		flag->precision = 0;
}

void	process_flag(t_flag *flag, int nlen)
{
	process_fill(flag);
	process_width(flag, nlen);
	process_precision(flag, nlen);
}
