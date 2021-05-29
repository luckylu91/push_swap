/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:41:13 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 11:46:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push(t_dequeue *q1, t_dequeue *q2)
{
	t_bilist	*elem;

	if (q1->size == 0)
		return ;
	elem = pop_first(q1);
	push_top(q2, elem);
}

void	push_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		push(stacks->b, stacks->a);
	else
		push(stacks->a, stacks->b);
}
