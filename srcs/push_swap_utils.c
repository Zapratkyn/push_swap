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

void	ft_reset_target(t_list *b)
{
	t_element	*temp;

	temp = b->first;
	while (temp)
	{
		temp->target_pos = INT_MAX;
		temp = temp->next;
	}
}

void	ft_target_pos(t_list *a, t_list *b)
{
	t_element	*indexx;
	t_element	*temp;

	
	ft_reset_target(b);
	temp = b->first;
	while (temp)
	{
		indexx = a->first;
		while (indexx)
		{
			if (indexx->index > temp->index && indexx->index < temp->target_pos)
				temp->target_pos = indexx->index;
			indexx = indexx->next;
		}
		if (temp->target_pos == INT_MAX)
		{
			indexx = a->first;
			while (indexx)
			{
				if (indexx->index < temp->target_pos)
					temp->target_pos = indexx->index;
				indexx = indexx->next;
			}
		}
		temp = temp->next;
	}
}

int	ft_pos(t_list *a, t_list *b)
{
	int 		i;
	t_element	*temp;

	i = 0;
	temp = a->first;
	while (temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
	i = 0;
	temp = b->first;
	while (temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_index(t_list *a, int k)
{
	int			i;
	t_element	*indexx;
	t_element	*temp;

	i = 1;
	while (i <= k)
	{
		indexx = a->first;
		while (indexx->index != -1 && indexx->next)
			indexx = indexx->next;
		temp = indexx;
		if (indexx->next)
			indexx = indexx->next;
		while (indexx->next)
		{
			if (indexx->number < temp->number && indexx->index == -1)
				temp = indexx;
			indexx = indexx->next;
		}
		if (indexx->number < temp->number && indexx->index == -1)
			temp = indexx;
		temp->index = i++;
	}
}
