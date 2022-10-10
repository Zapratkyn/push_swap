# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:55:30 by gponcele          #+#    #+#              #
#    Updated: 2022/10/04 13:12:01 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap
SRC						= srcs/main.c srcs/ft_sort.c srcs/push_swap_utils.c srcs/push.c srcs/rotate.c srcs/short_swap.c srcs/swap.c \
							libft/ft_errors.c libft/ft_success.c libft/ft_putendl_fd.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_free.c \
							libft/ft_printf.c libft/ft_print_chars.c libft/ft_print_nbr.c libft/ft_print_others.c
NORM					= @norminette
CC						= gcc
RM						= rm -rf
INCLUDES				= -I./includes
CFLAGS					= -Wall -Wextra -Werror
OBJS					= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(INCLUDES) $(SRC) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re