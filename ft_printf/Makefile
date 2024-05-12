# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 17:57:38 by stales            #+#    #+#              #
#    Updated: 2022/05/12 14:57:04 by stales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPRINTF_SRC	:= ft_printf.c 	\
				   ft_putchar.c \
				   ft_puthex.c	\
				   ft_putnbr.c	\
				   ft_putstr.c	\
				   ft_putnu.c

OBJ				:= $(FTPRINTF_SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -I ../includes -g
NAME			:= ../lib/libftprintf.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:			clean
	@$(RM) $(NAME) $(OBJ)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
