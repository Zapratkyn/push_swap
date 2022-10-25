/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:48 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 15:39:43 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_strnstr_check(char *str)
{
	if (ft_strnstr(str, "	sa(", 4))
		return (1);
	else if (ft_strnstr(str, "	sb(", 4))
		return (1);
	else if (ft_strnstr(str, "	ss(", 4))
		return (1);
	else if (ft_strnstr(str, "	pa(", 4))
		return (1);
	else if (ft_strnstr(str, "	pb(", 4))
		return (1);
	else if (ft_strnstr(str, "	ra(", 4))
		return (1);
	else if (ft_strnstr(str, "	rb(", 4))
		return (1);
	else if (ft_strnstr(str, "	rr(", 4))
		return (1);
	else if (ft_strnstr(str, "	rra(", 5))
		return (1);
	else if (ft_strnstr(str, "	rrb(", 5))
		return (1);
	else if (ft_strnstr(str, "	rrr(", 5))
		return (1);
	return (0);
}

void	check_ft(void)
{
	int		fd;
	int		a;
	char	*str;

	a = 0;
	fd = open("includes/push_swap.h", O_RDONLY);
	str = get_next_line(fd);
	a += ft_strnstr_check(str);
	free(str);
	while (str)
	{
		a += ft_strnstr_check(str);
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	if (a != 11)
		error("Error");
}
