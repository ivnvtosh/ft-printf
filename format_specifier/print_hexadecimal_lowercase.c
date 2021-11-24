/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_lowercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:07:47 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:07:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void	ft_recursion(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + 48, 1);
	else if (n < 16)
		ft_putchar_fd(n + 87, 1);
	else
	{
		ft_recursion(n / 16);
		ft_recursion(n % 16);
	}
}

static int	ft_nbrlen(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	print_hexadecimal_lowercase(unsigned int n)
{
	ft_recursion(n);
	return (ft_nbrlen(n));
}
