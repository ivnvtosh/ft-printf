/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:00:41 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/30 18:00:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_BONUS_H
# define PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf_bonus(const char *s, ...);

int		print_part_bonus(const char **ps);
void	print_number_bonus(char *s, unsigned long n, unsigned long mode);
int		nbrlen_bonus(unsigned long n, int mode);

int		print_char_bonus(char c);
int		print_string_bonus(char *s);
int		print_pointer_bonus(unsigned long int n);
int		print_decimal_bonus(long n);
int		print_unsigned_decimal_bonus(unsigned int n);
int		print_hexadecimal_lowercase_bonus(unsigned int n);
int		print_hexadecimal_uppercase_bonus(unsigned int n);

#endif
