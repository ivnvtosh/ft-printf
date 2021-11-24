/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:09:00 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 15:47:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	p1 = dst;
	p2 = src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
