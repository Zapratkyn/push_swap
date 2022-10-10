/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 15:26:59 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_list *stack, int i)
{
	t_element	*index;
	t_element	*temp;

	temp = stack->first;
	stack->first = stack->first->next;
	temp->next = NULL;
	index = stack->first;
	while (index->next)
		index = index->next;
	index->next = temp;
	if (i == 1 && stack->label == 'a')
		ft_printf("ra\n");
	else if (i == 1 && stack->label == 'b')
		ft_printf("rb\n");
	return (1);
}

int	rr(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rr\n");
	return (1);
}

int	reverse_rotate(t_list *stack, int i)
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
	if (i == 1 && stack->label == 'a')
		ft_printf("rra\n");
	else if (i == 1 && stack->label == 'b')
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
	return (1);
}
