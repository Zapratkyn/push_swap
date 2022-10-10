/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:02:55 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:16 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/libft.h"

// main.c
int								a_is_sorted(t_list *stack);
void							check_args(t_list *a, char **argv);
t_list							*initialisation(char c);
void							fill_a(t_list *a, int nb);
void                            ft_display(t_list *a);
// push_swap_utils.c
int								ft_no_double(t_list *a);
int								ft_bin_len(int k);
void							ft_bin(t_list *a, int k);
void							ft_pos(t_list *a, int k);
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
int								ft_sortest(t_list *a, t_list *b, int len, int k);
int								ft_sort(t_list *a, int k);

#endif