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

int	ft_sortest(t_list *a, t_list *b, int j, int k)
{
	int			op;
	int			i;

	op = 0;
	while (j >= 0)
	{
		i = k;
		while (i > 0)
		{
			if (a->first->bin[j] == 0)
				op += push_b(a, b);
			else if (a->first->bin[j] == 1)
				op += rotate(a, 1);
			i--;
		}
		while (b->first)
			op += push_a(a, b);
		j--;
	}
	return (op);
}

int	ft_sort(t_list *a, int k)
{
	t_list	*b;
	int		op;
	int		j;

	ft_pos(a, k);
	b = initialisation('b');
	if (!b)
		error2("Error", a);
	j = (ft_bin_len(k) - 1);
	op = ft_sortest(a, b, j, k);
	if (b->first)
	{
		if (b->first->next)
			ft_free(b);
		else
		{
			free(b->first);
			free(b);
		}
		error2("Error", a);
	}
	free(b);
	return (op);
}
