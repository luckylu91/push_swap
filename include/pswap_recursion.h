/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_recursion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:35:05 by lzins             #+#    #+#             */
/*   Updated: 2021/06/05 09:34:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_RECURSION_H
# define PSWAP_RECURSION_H

# include "common.h"
# include "operations.h"
# include "libft.h"
# include "dequeue.h"
# include "_trace.h"

// operations
void	ps_push_ab(t_stacks *stacks, int op_code);
void	ps_swap_ab(t_stacks *stacks, int op_code);
void	ps_rotate_ab(t_stacks *stacks, int op_code);
void	ps_rotate_reverse_ab(t_stacks *stacks, int op_code);
void	ps_push_n(t_stacks *s, int op_code, int n);
void	ps_rotate_n(t_stacks *s, int op_code, int n);
void	ps_rotate_reverse_n(t_stacks *s, int op_code, int n);
// utils
int		*list_to_array(t_bilist *lst, int n);
int		less_equal(int x, int y);
int		great_equal(int x, int y);
void	bubble_sort(int *array, int n);
t_push_strat	best_push_strategy(int *indices, int n_push, int n);
void	push_half(t_stacks *s, int op_code, int start, int n);
// main
int		push_half_in_a(t_stacks *s, int start, int n);
int		push_half_in_b(t_stacks *s, int start, int n);
void	sort_rec_a(t_stacks *s, int start, int na);
void	sort_rec_b(t_stacks *s, int start, int nb);
// push_half
void	set_push_data(t_stacks *s, int op_code, int start, t_push_data *d);
void	push_half_part(t_stacks *s, int op_code, t_push_data *d, int do_reverse);

#endif
