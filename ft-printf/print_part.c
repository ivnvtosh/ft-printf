/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:12:19 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 16:13:55 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_part(const char **ps)
{
	char	*s;
	int		i;

	s = *ps;
	i = 0;
	while (s[i] != '%' && s[i] != '\0')
		i++;
	*ps += write(1, s, i);
	return (i);
}
