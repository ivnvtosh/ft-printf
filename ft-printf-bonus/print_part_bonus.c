/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_part_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:59:52 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 17:59:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"
#include "../libft/libft.h"

int	print_part(const char **ps)
{
	const char	*s;
	int			i;

	s = *ps;
	i = 0;
	while (s[i] != '%' && s[i] != '\0')
		i++;
	*ps += write(1, s, i);
	return (i);
}
