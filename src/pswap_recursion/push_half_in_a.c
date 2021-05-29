/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:34:15 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:32:19 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int	choose_direction_a(t_dequeue *q, int n, int median)
{
	int i;
	int range[2];
	int k;
	t_bilist *blst;

	blst = q->first;
	range[0] = -1;
	range[1] = -1;
	i = 0;
	while (blst && i < n)
	{
		k = int_at(blst);
		if (k > median)
		{
			if (range[0] == -1)
				range[0] = i;
			range[1] = i;
		}
		i++;
		blst = blst->next;
	}
	if (range[1] < q->size - range[0])
		return (1);
	else
		return (-1);
}

int	push_half_in_a(t_stacks *s, int start, int n)
{
	int	median;
	int	direction;
	int	n_push;

	median = start - (n - 1 - n / 2);
	direction = choose_direction_a(s->b, n, median);
	n_push = n / 2;
	while (n_push > 0)
	{
		while (int_at(s->b->first) <= median)
		{
			if (direction > 0)
				ps_rotate_ab(s, 1);
			else
				ps_rotate_reverse_ab(s, 1);
		}
		ps_push_ab(s, 0);
		n_push--;
	}
	return (n / 2);
}
