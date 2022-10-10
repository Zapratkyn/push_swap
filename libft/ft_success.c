/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:48 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 14:19:30 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	success(char *msg, t_list *a)
{
	ft_putendl_fd(msg, 1);
	free(a->first);
	free(a);
	exit(EXIT_SUCCESS);
}

void	success2(char *msg, t_list *a)
{
	ft_putendl_fd(msg, 1);
	ft_free(a);
	exit(EXIT_SUCCESS);
}

void	success3(t_list *a, int op)
{
	ft_printf("Numbers have been sorted in %d operation", op);
	if (op > 1)
		write(1, "s", 1);
	ft_printf(". Well done.\n");
	ft_free(a);
	free(a->first);
	free(a);
	exit(EXIT_SUCCESS);
}
