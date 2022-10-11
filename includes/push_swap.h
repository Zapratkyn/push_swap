/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:02:55 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/11 12:11:42 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/libft.h"

// main.c
int								a_is_sorted(t_list *stack);
void							check_args(t_list *a, char **argv);
t_list							*initialisation(char a);
void							fill_a(t_list *a, int nb);
// push_swap_utils.c
int								ft_no_double(t_list *a);
void	    					ft_target_pos(t_list *a, t_list *b);
int	                            ft_pos(t_list *a, t_list *b);
void	                        ft_index(t_list *a, int k);
int                             ft_abs(int i);
// push.c
int								push_a(t_list *a, t_list *b);
int								push_b(t_list *a, t_list *b);
// rotate.c
int								rotate(t_list *stack, int i);
int								rr(t_list *stack_a, t_list *stack_b);
int								reverse_rotate(t_list *stack, int i);
int								rrr(t_list *stack_a, t_list *stack_b);
// swap.c
int								swap(t_list *stack, int i);
int								ss(t_list *stack_a, t_list *stack_b);
// short_swap.c
int								sort_small_stack(t_list *a, int argc);
int								three_args(t_list *a);
int								four_or_five_args(t_list *a, int argc);
int								ft_sorter(int i, int j, t_list *a, t_list *b);
// ft_sort.c
int								ft_total(t_element *temp, t_element *index);
void	                        ft_cost(t_list *a, t_list *b, int i, int k);
t_element	                    *ft_pick(t_list *a, t_list *b);
int								ft_sortest(t_list *a, t_list *b, t_element *temp);
int								ft_sort(t_list *a, int k);
// ft_sortest_options.c
int                             ft_option_1(t_list *a, t_list *b,
                                    t_element *index_a, t_element *temp);
int                             ft_option_2(t_list *a, t_list *b,
                                    t_element *index_a, t_element *temp);
int                             ft_option_3(t_list *stack, t_element *element);
int                             ft_option_4(t_list *stack, t_element *element);
// ft_edges.c
int                             ft_finalisation(t_list *a, int k);
int	                            ft_initial_push(t_list *a, t_list *b, int k);

#endif