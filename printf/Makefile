# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 16:47:50 by mariojim          #+#    #+#              #
#    Updated: 2024/02/25 19:18:24 by mariojim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIB = ft_printf.h

FTS = ft_utoa.c ft_strdup.c ft_itoa.c ft_ltohex.c ft_strjoin.c ft_itohex.c ft_printf.c ft_ptoa.c ft_putchar_fd.c ft_strlcpy.c ft_strlen.c ft_stolower.c

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
