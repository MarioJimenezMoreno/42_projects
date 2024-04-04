# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 16:47:50 by mariojim          #+#    #+#              #
#    Updated: 2024/03/24 17:23:24 by mariojim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIB = ft_printf.h

FTS = ft_utoa.c ft_libft_utils.c ft_itoa.c ft_printf.c ft_converters.c

OBJS = $(FTS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c	$(LIB) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
