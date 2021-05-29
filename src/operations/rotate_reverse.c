/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:12:57 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:15:45 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_reverse(t_dequeue *q)
{
	t_bilist	*first;

	if (q->size <= 1)
		return ;
	first = pop_first(q);
	push_bottom(q, first);
}

void	rotate_reverse_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		rotate_reverse(stacks->a);
	else if (op_code == 1)
		rotate_reverse(stacks->b);
	else
	{
		rotate_reverse(stacks->a);
		rotate_reverse(stacks->b);
	}
}
