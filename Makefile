# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:55:30 by gponcele          #+#    #+#              #
#    Updated: 2022/10/18 13:50:13 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap
NAME_BONUS				= checker
SRC						= srcs/main.c srcs/ft_sort.c srcs/push_swap_utils.c srcs/push.c srcs/rotate.c srcs/short_swap.c srcs/swap.c \
							srcs/ft_sortest_options.c srcs/ft_edges.c srcs/reverse_rotate.c
SRC_BONUS				= srcs/main_bonus.c srcs/ft_sort.c srcs/push_swap_utils.c srcs/push.c srcs/rotate.c srcs/short_swap.c srcs/swap.c \
							srcs/ft_sortest_options.c srcs/ft_edges.c srcs/reverse_rotate.c srcs/check_ft.c
LIBFT					= ./libft/libft.a
NORM					= @norminette
CC						= gcc
RM						= rm -rf
INCLUDES				= -I./includes
CFLAGS					= -Wall -Wextra -Werror
OBJS					= $(SRC:.c=.o)
OBJS_BONUS				= $(SRC_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_BONUS) -o $(NAME_BONUS)

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
			rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re