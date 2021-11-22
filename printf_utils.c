/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:09 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/22 20:54:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	slen;

	slen = 0;
	while (s[slen])
		slen++;
	return (slen);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_recursion(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_recursion(n / 10, fd);
		ft_recursion(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd(45, fd);
		ft_recursion(n * -1, fd);
	}
	else
		ft_recursion(n, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
