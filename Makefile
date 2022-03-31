# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:44:11 by sjeuneje          #+#    #+#              #
#    Updated: 2022/03/28 11:30:03 by sjeuneje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	srcs/parsing.c srcs/pipex.c srcs/main.c srcs/pipex_helper.c\
		libft/ft_split.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_substr.c libft/ft_calloc.c libft/ft_bzero.c\
		ft_printf/ft_print_char.c ft_printf/ft_print_integers.c ft_printf/ft_print_str.c ft_printf/ft_print_upper_hexa.c\
		ft_printf/ft_print_hexa.c ft_printf/ft_print_pointer.c  ft_printf/ft_print_unsintegers.c ft_printf/ft_printf.c ft_printf/ft_putchar.c\

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

exe:		all clean

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		exe clean fclean re