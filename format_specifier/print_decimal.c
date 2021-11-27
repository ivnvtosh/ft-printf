/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:00:30 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:00:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	ft_recursion(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + 48, 1);
	else
	{
		ft_recursion(n / 10);
		ft_recursion(n % 10);
	}
}

static int	ft_nbrlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	print_decimal(o_list *list, long n)
{
	int	len;

	len = ft_nbrlen(n);
	if (list->sign == 1 && n > 0)
		len += print_char('+');
	if (list->ch == '0' && n < 0)
	{
		len += print_char('-');
		n *= -1;
	}
	if (list->ch == ' ' && n < 0)
		len++;
	if (list->count > 0)
		len += ft_justify(list->count - len, list->ch);
	if (list->ch == ' ' && n < 0)
	{
		print_char('-');
		n *= -1;
	}
	ft_recursion(n);
	if (list->count < 0)
		len += ft_justify(list->count * -1 - len, list->ch);
	return (len);
}
