/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 12:58:38 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_list *stack)
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
	ft_printf("ra\n");
	return (1);
}

int	rb(t_list *stack)
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
	ft_printf("rb\n");
	return (1);
}

int	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
	return (1);
}
