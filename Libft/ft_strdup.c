/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:59:38 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 17:52:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * (slen));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, slen);
	return (s2);
}
