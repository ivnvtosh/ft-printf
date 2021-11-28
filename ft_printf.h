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

typedef struct o_list
{
	int	space;
	int	sign;
	int	ch;
	int	count;
	int	precision;
}	o_list;

int	ft_printf(const char *s, ...);

int	print_char(char c);
int	print_string(char *s);
int	print_pointer(unsigned long int n);
int	print_decimal(o_list *list, int n);
int	print_unsigned_decimal(unsigned int n);
int	print_hexadecimal_lowercase(unsigned int n);
int	print_hexadecimal_uppercase(unsigned int n);

int	ft_justify(int count, char c);

#endif
