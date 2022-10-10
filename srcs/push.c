/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/03 13:56:56 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_a(t_list *a, t_list *b)
{
	t_element	*temp;

	if (b->first == NULL)
		return (0);
	temp = b->first;
	if (b->first->next)
		b->first = b->first->next;
	else if (!b->first->next)
		b->first = NULL;
	temp->next = a->first;
	a->first = temp;
	ft_printf("pa\n");
	return (1);
}

int	push_b(t_list *a, t_list *b)
{
	t_element	*temp;

	if (a->first == NULL)
		return (0);
	temp = a->first;
	if (a->first->next)
		a->first = a->first->next;
	else if (!a->first->next)
		a->first = NULL;
	temp->next = b->first;
	b->first = temp;
	ft_printf("pb\n");
	return (1);
}
