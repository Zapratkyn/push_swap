/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:43:39 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:22:17 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_small_stack(t_list *a, int argc)
{
	int	op;

	op = 0;
	if (argc == 2)
		op += sa(a);
	else if (argc == 3)
		op += three_args(a);
	return (op);
}

int	three_args(t_list *a)
{
	int	str[3];
	int	op;

	op = 0;
	str[0] = a->first->number;
	str[1] = a->first->next->number;
	str[2] = a->first->next->next->number;
	if (str[1] < str[0] && str[0] < str[2])
		op += sa(a);
	else if (str[2] < str[1] && str[1] < str[0])
	{
		op += sa(a);
		op += rra(a);
	}
	else if (str[1] < str[2] && str[2] < str[0])
		op += ra(a);
	else if (str[0] < str[2] && str[2] < str[1])
	{
		op += sa(a);
		op += ra(a);
	}
	else if (str[2] < str[0] && str[0] < str[1])
		op += rra(a);
	return (op);
}
