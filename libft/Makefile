# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:52:45 by gponcele          #+#    #+#              #
#    Updated: 2022/10/18 15:03:27 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					=	ft_errors.c ft_success.c ft_putendl_fd.c ft_atoi.c ft_strlen.c ft_free.c \
								ft_printf.c ft_print_chars.c ft_print_nbr.c ft_print_others.c ft_errors.c \
								ft_success.c ft_free.c get_next_line.c get_next_line_utils.c ft_strnstr.c 
OBJS					= 	$(SRCS:.c=.o)
BONUS_OBJS				= 	$(BONUS_SRCS:.c=.o)
CC						= 	gcc
RM						= 	rm -f
CFLAGS					= 	-Wall -Wextra -Werror
NAME					= 	libft.a

all:					$(NAME)

$(NAME):				$(OBJS)
								ar rcs $(NAME) $(OBJS)
bonus:	 				$(BONUS_OBJS) $(OBJS)
								ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
								$(RM) $(OBJS) $(BONUS_OBJS)
fclean:					clean
								$(RM) $(NAME)
re:								fclean $(NAME)
.PHONY					=all clean fclean re
