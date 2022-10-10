/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:20 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_no_double(t_list *a)
{
	t_element	*temp;
	t_element	*index;

	index = a->first;
	while (index->next)
	{
		temp = index->next;
		while (temp->next)
		{
			if (temp->number == index->number)
				return (0);
			temp = temp->next;
		}
		if (temp->number == index->number)
			return (0);
		index = index->next;
	}
	return (1);
}

int	ft_bin_len(int k)
{
	if (k < 8)
		return (3);
	else if (k < 16)
		return (4);
	else if (k < 32)
		return (5);
	else if (k < 64)
		return (6);
	else if (k < 128)
		return (7);
	else if (k < 256)
		return (8);
	return (9);
}

void	ft_bin(t_list *a, int k)
{
	t_element	*temp;
	int			i;

	i = ft_bin_len(k);
	temp = a->first;
	while (temp->next)
	{
		k = i - 1;
		temp->bin = malloc (sizeof(int) * i);
		if (!temp->bin)
			error2("Error", a);
		while (k >= 0)
		{
			temp->bin[k--] = temp->pos % 2;
			temp->pos = temp->pos / 2;
		}
		temp = temp->next;
	}
	k = i - 1;
	temp->bin = malloc (sizeof(int) * i);
	if (!temp->bin)
		error2("Error", a);
	while (k >= 0)
	{
		temp->bin[k--] = temp->pos % 2;
		temp->pos = temp->pos / 2;
	}
}

void	ft_pos(t_list *a, int k)
{
	int			i;
	t_element	*index;
	t_element	*temp;

	i = 0;
	index = a->first;
	while (index->next)
		index = index->next;
	while (i < k)
	{
		index = a->first;
		while (index->pos != -1 && index->next)
			index = index->next;
		temp = index;
		if (index->next)
			index = index->next;
		while (index->next)
		{
			if (index->number < temp->number && index->pos == -1)
				temp = index;
			index = index->next;
		}
		if (index->number < temp->number && index->pos == -1)
			temp = index;
		temp->pos = i++;
	}
	ft_bin(a, k);
}
