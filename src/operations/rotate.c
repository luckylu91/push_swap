/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:15:55 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:16:23 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate(t_dequeue *q)
{
	t_bilist	*last;

	if (q->size <= 1)
		return ;
	last = pop_last(q);
	push_top(q, last);
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