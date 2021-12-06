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

typedef struct o_list
{
	int	space;
	int	hashtag;
	int	sign;
	int	fill;
	int	width;
	int	point;
	int	precision;
}	o_list;

int		ft_printf(const char *s, ...);

int		print_part(const char **ps);
void	print_number(char *s, unsigned long n, unsigned long mode);
int		nbrlen(unsigned long n, int mode);

int		print_char(o_list *flags, char c);
int		print_string(o_list *flags, char *s);
int		print_pointer(o_list *flags, unsigned long int n);
int		print_decimal(o_list *flags, long n);
int		print_unsigned_decimal(o_list *flags, unsigned int n);
int		print_hexadecimal_lowercase(o_list *flags, unsigned int n);
int		print_hexadecimal_uppercase(o_list *flags, unsigned int n);

void	process_flags(o_list *flags, unsigned int n);

int		print_space(int count, char c);
void	print_sign(o_list *flags);
void	print_width(o_list *flags);
void	print_precision(o_list *flags);

void	variant_1(o_list *flags);
void	variant_2(o_list *flags, char *s, unsigned int n);
void	variant_3(o_list *flags, char *s, unsigned int n);
void	variant_4(o_list *flags, char *s, unsigned int n);
void	variant_5(o_list *flags, char *s, unsigned int n);
#endif
