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

typedef struct s_flag
{
	int	space;
	int	hashtag;
	int	sign;
	int	fill;
	int	width;
	int	point;
	int	precision;
}	t_flags;

int		ft_printf(const char *s, ...);

int		print_part(const char **ps);
void	print_number(char *s, unsigned long n, unsigned long mode);
int		nbrlen(unsigned long n, int mode);

int		print_char(t_flags *flags, char c);
int		print_string(t_flags *flags, char *s);
int		print_pointer(t_flags *flags, unsigned long int n);
int		print_decimal(t_flags *flags, long n);
int		print_unsigned_decimal(t_flags *flags, unsigned int n);
int		print_hexadecimal_lowercase(t_flags *flags, unsigned int n);
int		print_hexadecimal_uppercase(t_flags *flags, unsigned int n);

int		getcount(t_flags *flags, int nlen);
void	process_flags(t_flags *flags, int nlen);
void	print_flag_nbr(t_flags *flags, char *s, unsigned long n);

void	print_nchar(char c, int len);
void	print_sign(t_flags *flags);
void	print_width(t_flags *flags);
void	print_precision(t_flags *flags);

void	variant_1(t_flags *flags);
void	variant_2(t_flags *flags, char *s, unsigned long n);
void	variant_3(t_flags *flags, char *s, unsigned long n);
void	variant_4(t_flags *flags, char *s, unsigned long n);
void	variant_5(t_flags *flags, char *s, unsigned long n);

#endif
