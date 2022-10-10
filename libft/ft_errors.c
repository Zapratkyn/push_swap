/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:09 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 11:54:36 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error2(char *msg, t_list *list)
{
	ft_putendl_fd(msg, 2);
	if (list->first)
	{
		if (list->first->next)
			ft_free(list);
		free(list->first);
	}
	free(list);
	exit (EXIT_FAILURE);
}
