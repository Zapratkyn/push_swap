/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:17:24 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_list *stack)
{
	t_element	*temp;
	t_element	*index;

	index = stack->first;
	while (index->next->next)
		index = index->next;
	temp = index->next;
	index->next = NULL;
	temp->next = stack->first;
	stack->first = temp;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list *stack)
{
	t_element	*temp;
	t_element	*index;

	index = stack->first;
	while (index->next->next)
		index = index->next;
	temp = index->next;
	index->next = NULL;
	temp->next = stack->first;
	stack->first = temp;
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
	return (1);
}
