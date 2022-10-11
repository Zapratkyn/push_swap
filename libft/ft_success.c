/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:48 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:55:31 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	success(char *msg, t_list *a, t_list *b)
{
	ft_putendl_fd(msg, 1);
	free(a->first);
	free(a);
	free(b);
	exit(EXIT_SUCCESS);
}

void	success2(char *msg, t_list *a, t_list *b)
{
	ft_putendl_fd(msg, 1);
	ft_free(a);
	free(a->first);
	free(a);
	free(b);
	exit(EXIT_SUCCESS);
}

void	success3(t_list *a, t_list *b, int op)
{
	(void)op;
	ft_free(a);
	free(a->first);
	free(a);
	free(b);
	exit(EXIT_SUCCESS);
}
