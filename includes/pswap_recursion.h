/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_recursion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:35:05 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 16:21:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_RECURSION_H
# define PSWAP_RECURSION_H

#include "common.h"
#include "operations.h"
#include "libft.h"
//
#include <stdio.h>

// exit
int		exit_fun_error(void *ctx);
int		exit_fun_ok(void *ctx);
// operations
void	ps_push_ab(t_stacks *stacks, int op_code);
void	ps_swap_ab(t_stacks *stacks, int op_code);
void	ps_rotate_ab(t_stacks *stacks, int op_code);
void	ps_rotate_reverse_ab(t_stacks *stacks, int op_code);
// utils
int	*list_to_array(t_list *lst, int n);
void	bubble_sort(int *array, int n);
// main
int	push_half_in_a(t_stacks *s, int n);
int	push_half_in_b(t_stacks *s, int n);
void	sort_rec_a(t_stacks *s, int na);
void	sort_rec_b(t_stacks *s, int nb);

#endif
