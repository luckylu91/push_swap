/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:34:15 by lzins             #+#    #+#             */
/*   Updated: 2021/06/05 09:10:02 by lzins            ###   ########lyon.fr   */
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
		if (k >= median)
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

// int	push_half_in_a(t_stacks *s, int start, int n)
// {
// 	int	median;
// 	int	direction;
// 	int	n_push;

// 	median = start - (n - 1 - n / 2);
// 	direction = choose_direction_a(s->b, n, median);
// 	n_push = n / 2;
// 	while (n_push > 0)
// 	{
// 		while (int_at(s->b->first) <= median)
// 		{
// 			if (direction > 0)
// 				ps_rotate_reverse_ab(s, 1);
// 			else
// 				ps_rotate_ab(s, 1);
// 		}
// 		ps_push_ab(s, 0);
// 		n_push--;
// 	}
// 	return (n / 2);
// }


// int	push_half_in_a(t_stacks *s, int start, int n)
// {
// 	int	median;
// 	int	n_push;
// 	int	direction;
// 	// int	n_rot;
// 	// int	n_rot_total;

// 	median = start - n / 2 + 1;
// 	n_push = n / 2;
// 	direction = choose_direction_a(s->b, n, median);
// 	// n_rot_total = 0;
// 	while (n_push > 0)
// 	{
// 		// n_rot = 0;
// 		while (int_at(s->b->first) < median)
// 		{
// 			// if (n_rot >= s->b->size)
// 			// {
// 			// 	printf("Problem in push_half_in_a");
// 			// 	ft_exit();
// 			// }
// 			if (direction > 0)
// 				ps_rotate_reverse_ab(s, 1);
// 			else
// 				ps_rotate_ab(s, 1);
// 			// ps_rotate_ab(s, 1);
// 			// n_rot++;
// 			// n_rot_total++;
// 		}
// 		ps_push_ab(s, 0);
// 		n_push--;
// 	}
// 	// while (n_rot_total-- > 0)
// 	// 	ps_rotate_ab(s, 1);
// 	return (n / 2);
// }

// int	push_half_in_a(t_stacks *s, int start, int n)
// {
// 	int	n_push;
// 	int	n_rot;
// 	int	median;

// 	n_push = n / 2;
// 	n_rot = 0;
// 	median = start - n / 2 + 1;
// 	while (n_push > 0)
// 	{
// 		// printf("size = %d\n", mvt.size);
// 		if (int_at(s->a->first) >= median)
// 		{
// 			ps_push_ab(s, 0);
// 			n_push--;
// 		}
// 		else
// 		{
// 			ps_rotate_ab(s, 1);
// 			n_rot++;
// 		}
// 	}
// 	if (need_rot)
// 		ps_rotate_reverse_n(s, 1, n_rot);
// 	return (n / 2);
// }
