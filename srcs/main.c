/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 14:43:17 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*initialisation(char a)
{
	t_list			*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->label = a;
	list->first = NULL;
	return (list);
}

void	fill_a(t_list *a, t_list *b, int nb)
{
	t_element			*temp;
	t_element			*index;
	static int			i = 1;

	temp = malloc(sizeof(t_element));
	if (!temp)
		error2("Error", a, b);
	temp->number = nb;
	temp->index = -1;
	temp->target_pos = INT_MAX;
	if (i == 1)
		a->first = temp;
	else if (i > 1)
	{
		index = a->first;
		while (index->next)
			index = index->next;
		index->next = temp;
	}
	i++;
}

void	check_args(t_list *a, t_list *b, char **argv)
{
	int			i;
	static int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_iszero(argv[i]))
			fill_a(a, b, 0);
		else
		{
			j = ft_atoi(argv[i]);
			if (!j)
				error2("Error", a, b);
			fill_a(a, b, j);
		}
		i++;
	}
	if (!ft_no_double(a))
		error2("Error", a, b);
}

int	a_is_sorted(t_list *stack)
{
	t_element	*temp;

	temp = stack->first;
	while (temp->next)
	{
		if (temp->number < temp->next->number)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static int	op = 0;
	t_list		*a;
	t_list		*b;

	if (argc == 1)
		error("Error");
	a = initialisation('a');
	b = initialisation('b');
	if (!a || !b)
		error2("Error", a, b);
	check_args(a, b, argv);
	if (!a->first->next)
		success("Only one number. Nothing to sort.", a, b);
	if (a_is_sorted(a))
		success2("Numbers are already sorted.", a, b);
	if (argc > 4)
		op += ft_sort(a, b, (argc - 1));
	else if (argc <= 4)
		op += sort_small_stack(a, (argc - 1));
	if (!a_is_sorted(a) || op == 0)
		error2("Error", a, b);
	success3(a, b, op);
}
