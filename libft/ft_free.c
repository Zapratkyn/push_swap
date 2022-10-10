/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:41 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/05 16:34:16 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_list *stack)
{
	t_element	*temp;
	t_element	*index;
	
	while(stack->first->next->next)
	{
		index = stack->first->next;
		temp = index->next->next;
		if (index->next->bin)
			free(index->next->bin);
		free(index->next);
		index->next = temp;
	}
	if (stack->first->next->bin)
		free(stack->first->next->bin);
	free(stack->first->next);
	if (stack->first->bin)
		free(stack->first->bin);
}