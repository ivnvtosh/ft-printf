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

MAIN	=	ft-printf/libftprintfmainpart.a
BONUS	=	ft-printf-bonus/libftprintfbonuspart.a
LIBFT	=	libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(MAIN) $(NAME)
			cp $(MAIN) $(NAME) 
			ar crs $(NAME) $(MAIN)

bonus	:	$(LIBFT) $(BONUS) $(NAME)
			cp $(BONUS) $(NAME) 
			ar crs $(NAME) $(BONUS)

$(MAIN)	:
			make -C ft-printf

$(BONUS):
			make -C ft-printf-bonus

$(LIBFT):
			make -C libft
			make -C libft clean

clean	:
			make -C ft-printf clean
			make -C ft-printf-bonus clean

fclean	:	clean
			make -C ft-printf fclean
			make -C ft-printf-bonus fclean

re		:	fclean all

.PHONY	:	all clean fclean re bonus
