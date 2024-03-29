/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:09 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 13:59:50 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error2(char *msg, t_list *a, t_list *b)
{
	ft_putendl_fd(msg, 2);
	if (a)
	{
		if (a->first)
		{
			if (a->first->next)
				ft_free(a);
			free(a->first);
		}
		free(a);
	}
	if (b)
		free(b);
	exit (EXIT_FAILURE);
}

void	error4(void)
{
	write (1, "\n", 1);
	exit(EXIT_FAILURE);
}
