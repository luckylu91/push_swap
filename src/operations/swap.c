/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:16:46 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:18:28 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(t_dequeue *q)
{
	t_bilist	*first;
	t_bilist	*second;

	if (q->size <= 1)
		return ;
	first = pop_first(q);
	second = pop_first(q);
	push_top(q, first);
	push_top(q, second);
}

void	swap_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		swap(stacks->a);
	else if (op_code == 1)
		swap(stacks->b);
	else
	{
		swap(stacks->a);
		swap(stacks->b);
	}
}
