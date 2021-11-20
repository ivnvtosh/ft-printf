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
HEADER	=	ft_printf.h

DIR		=	format-specifier

SRCS	=	ft_atoi.c       \
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c     \
			ft_memcmp.c     \
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c     \
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c    \
			ft_strnstr.c    \
			ft_strrchr.c    \
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c    \
			ft_toupper.c	\
			ft_printf		\
			$(DIR)/
			


CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
OPTION	=	-c -I $(HEADER)
RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar crs $(NAME) $(OBJS)

%.o		:	%.c $(HEADER)
			$(CC) -o $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
