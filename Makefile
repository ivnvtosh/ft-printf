# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:45:41 by ccamie            #+#    #+#              #
#    Updated: 2021/10/18 15:45:43 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	ft-printf/printf.h
HEADER_B	=	ft-printf-bonus/printf_bonus.h

LIBFT		=	libft/libft.a

SRCS		=	ft-printf/print_char.c					\
				ft-printf/print_decimal.c				\
				ft-printf/print_hexadecimal_lowercase.c	\
				ft-printf/print_hexadecimal_uppercase.c	\
				ft-printf/print_number.c				\
				ft-printf/print_part.c					\
				ft-printf/print_pointer.c				\
				ft-printf/print_string.c				\
				ft-printf/print_unsigned_decimal.c		\
				ft-printf/printf_utils.c				\
				ft-printf/ft_printf.c

SRCS_B		=	ft-printf-bonus/print_char_bonus.c					\
				ft-printf-bonus/print_decimal_bonus.c				\
				ft-printf-bonus/print_hexadecimal_lowercase_bonus.c	\
				ft-printf-bonus/print_hexadecimal_uppercase_bonus.c	\
				ft-printf-bonus/print_number_bonus.c				\
				ft-printf-bonus/print_part_bonus.c					\
				ft-printf-bonus/print_pointer_bonus.c				\
				ft-printf-bonus/print_string_bonus.c				\
				ft-printf-bonus/print_unsigned_decimal_bonus.c		\
				ft-printf-bonus/printf_utils_bonus.c				\
				ft-printf-bonus/print_nchar_bonus.c					\
				ft-printf-bonus/printf_variant_decimal_bonus.c		\
				ft-printf-bonus/printf_process_flags_bonus.c		\
				ft-printf-bonus/printf_flags_bonus.c				\
				ft-printf-bonus/ft_printf_bonus.c

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	crs
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJS)
				cp $(LIBFT) $(NAME) 
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus		:	$(LIBFT) $(OBJS_B) 
				cp $(LIBFT) $(NAME) 
				$(AR) $(ARFLAGS) $(NAME) $(OBJS_B)

$(LIBFT)	:
				make -C libft
				make -C libft clean

$(OBJS)		:	%.o	: %.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_B)	:	%.o	: %.c $(HEADER_B)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

rebonus		:	fclean bonus

.PHONY		:	all clean fclean re bonus
