# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:55:30 by gponcele          #+#    #+#              #
#    Updated: 2022/10/11 14:33:09 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap
SRC						= srcs/main.c srcs/ft_sort.c srcs/push_swap_utils.c srcs/push.c srcs/rotate.c srcs/short_swap.c srcs/swap.c \
							srcs/ft_sortest_options.c srcs/ft_edges.c srcs/reverse_rotate.c
LIBFT					= ./libft/libft.a
NORM					= @norminette
CC						= gcc
RM						= rm -rf
INCLUDES				= -I./includes
CFLAGS					= -Wall -Wextra -Werror
OBJS					= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re