/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 12:49:47 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_list *stack)
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
	ft_printf("sa\n");
	return (1);
}

int	sb(t_list *stack)
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
	ft_printf("sb\n");
	return (1);
}

int	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (1);
}
