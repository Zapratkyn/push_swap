/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 15:27:07 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list *stack, int i)
{
	t_element	*temp;
	t_element	*index;

	if (stack->first == NULL || stack->first->next == NULL)
		return (0);
	temp = stack->first->next->next;
	index = stack->first;
	stack->first = stack->first->next;
	stack->first->next = index;
	index->next = temp;
	if (i == 1 && stack->label == 'a')
		ft_printf("sa\n");
	else if (i == 1 && stack->label == 'b')
		ft_printf("sb\n");
	return (1);
}

int	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("ss\n");
	return (1);
}
