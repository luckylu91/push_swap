/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:23:09 by lzins             #+#    #+#             */
/*   Updated: 2021/04/17 13:49:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
#define OPERATIONS_H

// int	push(t_list **alst1, t_list **alst2);
// void	swap(t_list **alst);
// void	rotate(t_list **alst);
// void	rotate_reverse(t_list **alst);
int	push(t_list **alst1, t_list **alst2);
int	push_ab(t_stacks *stacks, int op_code);
int	swap_ab(t_stacks *stacks, int op_code);
int	rotate_ab(t_stacks *stacks, int op_code);
int	rotate_reverse_ab(t_stacks *stacks, int op_code);

#endif
