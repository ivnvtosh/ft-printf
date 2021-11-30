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

int	print_part(const char **ps)
{
	int	i;

	i = 0;
	while ((*ps)[i] != '%' && (*ps)[i] != '\0')
		i++;
	write(1, *ps, i);
	*ps += i;
	return (i);
}