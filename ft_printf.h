/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:24:12 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:24:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);

int	ft_is_char(va_list ap);
int	ft_is_decimal(va_list ap);
int	ft_is_hexadecimal(va_list ap);
int	ft_is_pointer(va_list ap);
int	ft_is_hexadecimal_X(va_list ap);
int  ft_is_0lo(char c, int fd);
int	ft_is_string(va_list ap);
int	ft_unsigned_decimal(va_list ap);

#endif
