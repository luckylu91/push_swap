/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:34:15 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:12:47 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int	choose_direction_a(t_bilist *lst, int n, int median, int lst_len)
{
	int i;
	int range[2];
	int k;

	range[0] = -1;
	range[1] = -1;
	i = 0;
	while (lst && i < n)
	{
		k = int_at(lst);
		if (k > median)
		{
			if (range[0] == -1)
				range[0] = i;
			range[1] = i;
		}
		i++;
		lst = lst->next;
	}
	if (range[1] < lst_len - range[0])
		return (1);
	else
		return (-1);
}

int	push_half_in_a(t_stacks *s, int n)
{
	int	median;
	int	*array;
	int	direction;
	int	n_push;

	array = list_to_array(s->b, n);
	bubble_sort(array, n);
	median = array[n - 1 - n / 2];
	direction = choose_direction_a(s->b, n, median, s->b_size);
	n_push = n / 2;
	while (n_push > 0)
	{
		while (int_at(s->b) <= median)
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
