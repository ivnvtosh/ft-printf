/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:14 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	print_string(char *s)
{
	if (s == NULL)
		return (print_string("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
