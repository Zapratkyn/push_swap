/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortest_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:50:15 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:12:50 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_option_1(t_list *a, t_list *b, t_element *index_a, t_element *temp)
{
	int	op;

	op = rr(a, b);
	index_a->cost_a -= 1;
	temp->cost_b -= 1;
	return (op);
}

int	ft_option_2(t_list *a, t_list *b, t_element *index_a, t_element *temp)
{
	int	op;

	op = rrr(a, b);
	index_a->cost_a += 1;
	temp->cost_b += 1;
	return (op);
}

int	ft_option_3(t_list *stack, t_element *element)
{
	int	op;

	op = 0;
	if (stack->label == 'a')
	{
		op = ra(stack);
		element->cost_a -= 1;
	}
	else if (stack->label == 'b')
	{
		op = rb(stack);
		element->cost_b -= 1;
	}
	return (op);
}

int	ft_option_4(t_list *stack, t_element *element)
{
	int	op;

	op = 0;
	if (stack->label == 'a')
	{
		op = rra(stack);
		element->cost_a += 1;
	}
	else if (stack->label == 'b')
	{
		op = rrb(stack);
		element->cost_b += 1;
	}
	return (op);
}
