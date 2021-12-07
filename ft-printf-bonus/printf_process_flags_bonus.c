/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_process_flags_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:31:27 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/07 20:31:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

static void	process_fill(t_flags *flags)
{
	int	width;

	if (flags->fill == 0 || flags->precision)
		flags->fill = ' ';
}

static void	process_width(t_flags *flags, int nlen)
{
	if (flags->hashtag)
		nlen += 2;
	if (flags->width > nlen && flags->width > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width -= flags->precision;
		else
			flags->width -= nlen;
	}
	else if (flags->width * -1 > nlen && flags->width * -1 > flags->precision)
	{
		if (flags->precision > nlen)
			flags->width += flags->precision;
		else
			flags->width += nlen;
	}
	else
		flags->width = 0;
	if (flags->width > 0 && (flags->sign || flags->space))
		flags->width -= 1;
	if (flags->width < 0 && (flags->sign || flags->space))
		flags->width += 1;
}

static void	process_precision(t_flags *flags, int nlen)
{
	if (flags->precision > nlen)
		flags->precision = flags->precision - nlen;
	else
		flags->precision = 0;
}

void	process_flags(t_flags *flags, int nlen)
{
	process_fill(flags);
	process_width(flags, nlen);
	process_precision(flags, nlen);
}
