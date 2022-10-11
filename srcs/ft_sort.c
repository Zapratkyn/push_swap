/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:50:15 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/04 15:27:42 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_initial_push(t_list *a, t_list *b, int k)
{
	// int			i;
	int			op;
	// t_element	*temp;

	(void)k;
	// i = 1;
	op = 0;
	// while (i <= k)
	// {
	// 	temp = a->first;
	// 	if (temp->index <= (k / 2))
	// 		op += push_b(a, b);
	// 	else if (temp->index > (k / 2))
	// 		op += rotate(a, 1);
	// 	i++;
	// }
	while (a->first->next->next->next)
		op += push_b(a, b);
	return (op);
}

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
	else if (temp->cost_b > 0)
		i += temp->cost_b;
	if (index->cost_a < 0)
		i += (index->cost_a * -1);
	else if (temp->cost_a > 0)
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

void	ft_display_target(t_list *b)
{
	t_element	*temp;

	ft_printf("\nCibles :\n");
	temp = b->first;
	while (temp)
	{
		ft_printf("%d ", temp->target_pos);
		temp = temp->next;
	}
	write (1, "\n", 1);
}

void	ft_display_index_a(t_list *a)
{
	t_element	*temp;

	write (1, "\n", 1);
	temp = a->first;
	while (temp)
	{
		ft_printf("%d ", temp->index);
		temp = temp->next;
	}
	write (1, "\n", 1);
}

void	ft_display_index(t_list *a, t_list *b)
{
	t_element	*temp;

	ft_printf("\nIndex :\n");
	temp = a->first;
	ft_printf("A : ");
	while (temp)
	{
		ft_printf("%d ", temp->index);
		temp = temp->next;
	}
	temp = b->first;
	ft_printf("\n\nB : ");
	while (temp)
	{
		ft_printf("%d ", temp->index);
		temp = temp->next;
	}
	write (1, "\n\n", 2);
}

void	ft_display_numbers(t_list *a, t_list *b)
{
	t_element	*temp;

	ft_printf("\nNombres :\n");
	temp = a->first;
	ft_printf("A : ");
	while (temp)
	{
		ft_printf("%d ", temp->number);
		temp = temp->next;
	}
	temp = b->first;
	ft_printf("\n\nB : ");
	while (temp)
	{
		ft_printf("%d ", temp->number);
		temp = temp->next;
	}
	write (1, "\n\n", 2);
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
	ft_display_numbers(a, b);
	while (b->first)
	{
		i = ft_pos(a, b);
		ft_target_pos(a, b);
		// ft_display_index(a, b);
		// ft_display_target(b);
		ft_cost(a, b, i, k);
		// ft_display_cost(a, b);
		// write (1, "\n", 1);
		temp = ft_pick(a, b);
		// ft_printf("Index du pick : %d\n\n", temp->index);
		op += ft_sortest(a, b, temp);
		ft_printf("=============\n");
		ft_display_numbers(a, b);
		
	}
	free(b);
	// ft_display_index_a(a);
	op += ft_finalisation(a, k);
	return (op);
}
