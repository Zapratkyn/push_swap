/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:43:39 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 15:29:41 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_small_stack(t_list *a, int argc)
{
	int	op = 0;

	op = 0;
	if (argc == 2)
		op += swap(a, 1);
	else if (argc == 3)
		op += three_args(a);
	else if (argc == 4 || argc == 5)
		op += four_or_five_args(a, argc);
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
		op += swap(a, 1);
	else if (str[2] < str[1] && str[1] < str[0])
	{
		op += swap(a, 1);
		op += reverse_rotate(a, 1);
	}
	else if (str[1] < str[2] && str[2] < str[0])
		op += rotate(a, 1);
	else if (str[0] < str[2] && str[2] < str[1])
	{
		op += swap(a, 1);
		op += rotate(a, 1);
	}
	else if (str[2] < str[0] && str[0] < str[1])
		op += reverse_rotate(a, 1);
	return (op);
}

int	ft_sorter(int i, int j, t_list *a, t_list *b)
{
	int			k;
	int			op;

	op = 0;
	k = b->first->number;
	if (k < i && k < j)
		op += push_a(a, b);
	else if (k > i && k < j)
	{
		while (k > a->first->number)
			op += rotate(a, 1);
		op += push_a(a, b);
		if (b->first)
		{
			while (b->first->number > a->first->number && a->first->number != i)
				op += rotate(a, 1);
			op += push_a(a, b);
		}
		while (!a_is_sorted(a))
			op += rotate(a, 1);
	}
	else if (k > i && k > j)
	{
		op += push_a(a, b);
		op += rotate(a, 1);
	}
	return (op);
}

int	four_or_five_args(t_list *a, int argc)
{
	t_list		*b;
	t_element	*temp;
	int			last_a;
	static int	op = 0;

	b = initialisation('b');
	if (!b)
		error2("Error", a);
	while (argc-- > 3)
		op += push_b(a, b);
	op += three_args(a);
	if (b->first->next && b->first->number > a->first->number)
		if (b->first->number > b->first->next->number)
			op += swap(b, 1);
	while (b->first != NULL)
	{
		temp = a->first;
		while (temp->next)
			temp = temp->next;
		last_a = temp->number;
		op += ft_sorter(a->first->number, last_a, a, b);
	}
	free(b);
	return (op);
}
