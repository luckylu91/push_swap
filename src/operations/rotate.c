/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:15:55 by lzins             #+#    #+#             */
/*   Updated: 2021/06/05 09:08:21 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate(t_dequeue *q)
{
	t_bilist	*first;

	if (q->size <= 1)
		return ;
	first = pop_first(q);
	push_bottom(q, first);
}

void	rotate_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		rotate(stacks->a);
	else if (op_code == 1)
		rotate(stacks->b);
	else
	{
		rotate(stacks->a);
		rotate(stacks->b);
	}
}
