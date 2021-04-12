/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:33:21 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 22:31:14 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "libft.h"
#include "common.h"
#include "operations.h"
#include <limits.h>

// utils
int	int_at(t_list *lst);
char	op_last_char(char op_char, int op_code);
// operations
void	ps_push_ab(t_stacks *stacks, int op_code);
void	ps_swap_ab(t_stacks *stacks, int op_code);
void	ps_rotate_ab(t_stacks *stacks, int op_code);
void	ps_rotate_reverse_ab(t_stacks *stacks, int op_code);
// init_divide
void	init_divide(t_stacks *stacks);
// merge
void	merge_ab(t_stacks *stacks, int na, int nb, int op_code);
void	merge_a2(t_stacks *stacks, int offset, int na2);
// sort
void	merge_sort(t_stacks *stacks);


#endif
