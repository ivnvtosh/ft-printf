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

NAME	=	libftprintf.a
LIBFT	=	libft/libft.a
HEADER	=	ft_printf.h

SRCS	=	print_char.c					\
			print_decimal.c					\
			print_hexadecimal_lowercase.c	\
			print_hexadecimal_uppercase.c	\
			print_number.c					\
			print_part.c					\
			print_pointer.c					\
			print_string.c					\
			print_unsigned_decimal.c		\
			printf_utils.c					\
			ft_printf.c

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
OPTION	=	-c -I $(HEADER)
RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
			cp $(LIBFT) $(NAME) 
			ar crs $(NAME) $(OBJS)

$(LIBFT):
			make -C libft

%.o		:	%.c $(HEADER)
			$(CC) -o $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
