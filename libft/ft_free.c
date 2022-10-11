/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:45:15 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_list *stack)
{
	t_element	*temp;
	t_element	*index;

	while (stack->first->next->next)
	{
		index = stack->first->next;
		temp = index->next->next;
		free(index->next);
		index->next = temp;
	}
	free(stack->first->next);
}
