/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edges.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:09:50 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/25 13:18:32 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_initial_push(t_list *a, t_list *b, int k)
{
	int			i;
	int			op;
	t_element	*temp;

	(void)k;
	i = 1;
	op = 0;
	while (i <= k && a->first->next->next->next)
	{
		temp = a->first;
		if (temp->index <= (k / 2))
			op += pb(a, b);
		else if (temp->index > (k / 2))
			op += ra(a);
		i++;
	}
	while (a->first->next->next->next)
		op += pb(a, b);
	return (op);
}

int	ft_finalisation(t_list *a, int k)
{
	int	op;

	op = 0;
	if (a->first->index <= (k / 2))
	{
		while (!a_is_sorted(a))
			op += rra(a);
	}
	else if (a->first->index > (k / 2))
	{
		while (!a_is_sorted(a))
			op += ra(a);
	}
	return (op);
}
