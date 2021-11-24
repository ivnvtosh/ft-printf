/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:32 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/16 15:54:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		sign;

	sign = 1;
	i = ft_len(n);
	p = (char *)malloc(sizeof(*p) * (i + 1));
	if (p == NULL)
		return (NULL);
	p[i--] = 0;
	p[0] = '0';
	if (n < 0)
	{
		p[0] = '-';
		sign = -1;
	}
	while (n)
	{
		p[i--] = n % 10 * sign + '0';
		n = n / 10;
	}
	return (p);
}
