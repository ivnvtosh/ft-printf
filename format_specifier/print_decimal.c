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

int	print_space(o_list *list)
{
	if (list->space == 1 && list->sign == 0)
		return (print_char(' '));
	return (0);
}

int	print_sign(int n, int sign)
{
	if (n > 0 && sign == 1)
		return (print_char('+'));
	if (n < 0)
		return (print_char('-'));
	return (0);
}

void	print_justify(o_list *list, unsigned int u, int len)
{
	int		count;
	char	c;

	if (list->precision > ft_nbrlen(u))
		count = list->count - list->precision - list->sign;
	else
		count = list->count - len - list->sign;
	if (list->precision > 0)
		c = ' ';
	else
		c = list->ch;
	while (count > 0)
	{
		print_char(c);
		count--;
	}
}

void	print_precision(o_list *list, int len)
{
	int	precision;

	precision = list->precision + list->sign - len;
	while (precision > 0)
	{
		print_char('0');
		precision--;
	}
}

int	print_one(o_list *list, int n)
{
	unsigned int	u;
	int				len;

	if (n >= 0)
		u = n;
	else
		u = -n;
	if (n < 0)
		list->sign = 1;
	len = ft_nbrlen(u);
	len += print_space(list);
	len += print_sign(n, list->sign);
	print_justify(list, u, len);
	print_precision(list, len);
	ft_recursion(u);
	return (len);
}

int	print_two(o_list *list, int n)
{
	unsigned int	u;
	int				len;

	if (n >= 0)
		u = n;
	else
		u = -n;
	if (n < 0)
		list->sign = 1;
	len = ft_nbrlen(u);
	len += print_space(list);
	print_justify(list, u, len);
	len += print_sign(n, list->sign);
	print_precision(list, len);
	ft_recursion(u);
	return (len);
}

int	print_three(o_list *list, int n)
{
	unsigned int	u;
	int				len;

	if (n >= 0)
		u = n;
	else
		u = -n;
	if (n < 0)
		list->sign = 1;
	len = ft_nbrlen(u);
	len += print_space(list);
	list->count = list->count * -1;
	len += print_sign(n, list->sign);
	print_precision(list, len);
	ft_recursion(u);
	print_justify(list, u, len);
	return (len);
}

int	print_decimal(o_list *list, int n)
{
	if (list->count >= 0)
	{
		if (list->ch == '0')
			return (print_one(list, n));
		else
			return (print_two(list, n));
	}
	else
		return (print_three(list, n));
	return (-100);
}
