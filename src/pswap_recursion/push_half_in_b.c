/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_in_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:33:41 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 03:08:04 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int	choose_direction_b(t_dequeue *q, int n, int median)
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
		if (k <= median)
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

// int	push_half_in_b(t_stacks *s, int start, int n)
// {
// 	int	median;
// 	int	direction;
// 	int	n_push;

// 	median = start + (n + 1) / 2;
// 	direction = choose_direction_b(s->a, n, median);
// 	n_push = n / 2;
// 	while (n_push > 0)
// 	{
// 		while (int_at(s->a->first) >= median)
// 		{
// 			if (direction > 0)
// 				ps_rotate_ab(s, 0);
// 			else
// 				ps_rotate_reverse_ab(s, 0);
// 		}
// 		ps_push_ab(s, 1);
// 		n_push--;
// 	}
// 	return ((n + 1) / 2);
// }

int	push_half_in_b(t_stacks *s, int start, int n)
{
	int	median;
	int	n_push;
	int	direction;
	// int	n_rot;
	// int	n_rot_total;

	median = start + n / 2 - 1;
	n_push = n / 2;
	// n_rot_total = 0;
	direction = choose_direction_b(s->a, n, median);
	while (n_push > 0)
	{
		// n_rot = 0;
		while (int_at(s->a->first) > median)
		{
			if (direction > 0)
				ps_rotate_ab(s, 0);
			else
				ps_rotate_reverse_ab(s, 0);
			// if (n_rot >= s->a->size)
			// {
			// 	printf("Problem in push_half_in_b");
			// 	ft_exit();
			// }
			// ps_rotate_reverse_ab(s, 0);
			// n_rot_total++;
			// n_rot++;
		}
		ps_push_ab(s, 1);
		n_push--;
	}
	// while (n_rot_total-- > 0)
	// 	ps_rotate_ab(s, 0);
	return (n - n / 2);
}
