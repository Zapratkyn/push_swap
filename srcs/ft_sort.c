/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:50:15 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 12:15:11 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_cost(t_list *a, t_list *b, int i, int k)
{
	t_element	*temp;

	temp = b->first;
	while (temp)
	{
		if (temp->pos <= (i / 2))
			temp->cost_b = temp->pos;
		else if (temp->pos > (i / 2))
			temp->cost_b = (i - temp->pos) * -1;
		temp = temp->next;
	}
	temp = a->first;
	while (temp)
	{
		if (temp->pos <= ((k - i) / 2))
			temp->cost_a = temp->pos;
		else if (temp->pos > ((k - i) / 2))
			temp->cost_a = ((k - i) - temp->pos) * -1;
		temp = temp->next;
	}
}

int	ft_total(t_element *temp, t_element *index)
{
	int	i;

	i = 0;
	if (temp->cost_b < 0)
		i += (temp->cost_b * -1);
	if (temp->cost_b > 0)
		i += temp->cost_b;
	if (index->cost_a < 0)
		i += (index->cost_a * -1);
	if (index->cost_a > 0)
		i += index->cost_a;
	return (i);
}

t_element	*ft_pick(t_list *a, t_list *b)
{
	t_element	*temp;
	t_element	*indexx;
	t_element	*result;
	int			cost;

	cost = INT_MAX;
	temp = b->first;
	result = temp;
	while (temp)
	{
		indexx = a->first;
		while (indexx)
		{
			if (indexx->index == temp->target_pos && ft_total(temp, indexx) < cost)
			{
				cost = ft_total(temp, indexx);
				result = temp;
			}
			indexx = indexx->next;
		}
		temp = temp->next;
	}
	return (result);
}

int	ft_sortest(t_list *a, t_list *b, t_element *temp)
{
	t_element	*index_a;
	int			op;

	op = 0;
	index_a = a->first;
	while (index_a->index != temp->target_pos)
		index_a = index_a->next;
	while (temp->cost_b != 0 || index_a->cost_a != 0)
	{
		while (temp->cost_b > 0 && index_a->cost_a > 0)
			op += ft_option_1(a, b, index_a, temp);
		while (temp->cost_b < 0 && index_a->cost_a < 0)
			op += ft_option_2(a, b, index_a, temp);
		while (temp->cost_b > 0)
			op += ft_option_3(b, temp);
		while (temp->cost_b < 0)
			op += ft_option_4(b, temp);
		while (index_a->cost_a > 0)
			op += ft_option_3(a, index_a);
		while (index_a->cost_a < 0)
			op += ft_option_4(a, index_a);
	}
	op += push_a(a, b);
	return (op);
}

int	ft_sort(t_list *a, int k)
{
	t_list		*b;
	t_element 	*temp;
	int			op;
	int			i;

	op = 0;
	ft_index(a, k);
	b = initialisation('b');
	if (!b)
		error2("Error", a);
	op += ft_initial_push(a, b, k);
	op += three_args(a);
	while (b->first)
	{
		i = ft_pos(a, b);
		ft_target_pos(a, b);
		ft_cost(a, b, i, k);
		temp = ft_pick(a, b);
		op += ft_sortest(a, b, temp);
	}
	free(b);
	op += ft_finalisation(a, k);
	return (op);
}
