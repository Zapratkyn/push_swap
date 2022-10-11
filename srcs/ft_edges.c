/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edges.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:09:50 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 12:10:38 by gponcele         ###   ########.fr       */
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
	while (i <= k)
	{
		temp = a->first;
		if (temp->index <= (k / 2))
			op += push_b(a, b);
		else if (temp->index > (k / 2))
			op += rotate(a, 1);
		i++;
	}
	while (a->first->next->next->next)
		op += push_b(a, b);
	return (op);
}

int    ft_finalisation(t_list *a, int k)
{
    int op;
    
    op = 0;
    if (a->first->index <= (k / 2))
    {
        while (!a_is_sorted(a))
            op += reverse_rotate(a, 1);
    }
    else if (a->first->index > (k / 2))
    {
        while (!a_is_sorted(a))
            op += rotate(a, 1);
    }
    return (op);
}
