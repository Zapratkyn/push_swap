/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:18:46 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/05 16:53:59 by gponcele         ###   ########.fr       */
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

void	fill_a(t_list *a, int nb)
{
	t_element			*temp;
	t_element			*index;
	static int			i = 1;

	temp = malloc(sizeof(t_element));
	if (!temp)
		error2("Error", a);
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

void	check_args(t_list *a, char **argv)
{
	int			i;
	static int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_iszero(argv[i]))
			fill_a(a, 0);
		else
		{
			j = ft_atoi(argv[i]);
			if (!j)
				error2("Error", a);
			fill_a(a, j);
		}
		i++;
	}
	if (!ft_no_double(a))
		error2("Error", a);
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

	if (argc == 1)
		error("Error");
	a = initialisation('a');
	if (!a)
		error("Error");
	check_args(a, argv);
	if (!a->first->next)
		success("Only one number. Nothing to sort.", a);
	if (a_is_sorted(a))
		success2("Numbers are already sorted.", a);
	if (argc > 6)
		op += ft_sort(a, (argc - 1));
	else if (argc <= 6)
		op += sort_small_stack(a, (argc - 1));
	if (!a_is_sorted(a) || op == 0)
		error2("Error", a);
	success3(a, op);
}
