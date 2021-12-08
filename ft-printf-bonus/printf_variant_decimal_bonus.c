/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_variant_decimal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:43:08 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/04 20:43:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

void	variant_1(t_flag *flag)
{
	if (flag->width < 0)
		flag->width = -flag->width;
	flag->width += 1;
	flag->fill = ' ';
	print_width(flag);
}

void	variant_2(t_flag *flag, char *s, unsigned long n)
{
	print_flag(flag);
	print_width(flag);
	print_precision(flag);
	print_number(s, n, ft_strlen(s));
}

void	variant_3(t_flag *flag, char *s, unsigned long n)
{
	print_width(flag);
	print_flag(flag);
	print_precision(flag);
	print_number(s, n, ft_strlen(s));
}

void	variant_4(t_flag *flag, char *s, unsigned long n)
{
	flag->width = -flag->width;
	print_flag(flag);
	print_precision(flag);
	print_number(s, n, ft_strlen(s));
	print_width(flag);
}

void	variant_5(t_flag *flag, char *s, unsigned long n)
{
	print_flag(flag);
	print_precision(flag);
	print_number(s, n, ft_strlen(s));
}
