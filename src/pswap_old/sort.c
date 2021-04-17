/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:49:49 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 22:38:10 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int		swap_code(t_stacks *stacks)
{
	int	code_plusone;

	code_plusone = 0;
	if (stacks->a && stacks->a->next
			&& int_at(stacks->a) > int_at(stacks->a->next))
		code_plusone += 1;
	if (stacks->b && stacks->b->next
			&& int_at(stacks->b) < int_at(stacks->b->next))
		code_plusone += 2;
	return (code_plusone - 1);
}

void	init_divide(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < (stacks->n - stacks->n % 4) / 2)
	{
		ps_push_ab(stacks, 1);
		// scode = swap_code(stacks);
		// if (scode >= 0)
		// 	ps_swap_ab(stacks, scode);
		// ps_push_ab(stacks, 1);
		// ps_push_ab(stacks, 1);
	}
}

//
#include <stdio.h>

int	sort_iteration(t_stacks *stacks, int k)
{
	int	remaining;
	int	excedant_group;
	int	n_merge;
	int	i;
	int	merge_code;
	int	scode;

	n_merge = stacks->n / (1 << (k + 1));
	if (n_merge == 0)
		return (0);
	excedant_group = stacks->n & (1 << k);
	remaining = stacks->n % (1 << k);
	printf("n = %d\n", stacks->n);
	printf("k = %d\n", k);
	printf("n_merge = %d\n", n_merge);
	printf("excedant_group = %d\n", excedant_group);
	printf("remaining = %d\n", remaining);
	merge_code = 0;
	i = -1;
	while (++i < n_merge)
	{
		if (k == 1)
		{
			scode = swap_code(stacks);
			if (scode >= 0)
				ps_swap_ab(stacks, scode);
		}
		merge_ab(stacks, (1 << k), (1 << k), merge_code);
		merge_code = 1 - merge_code;
	}
	if (excedant_group)
	{
		if (k == 1 && stacks->a && stacks->a->next
				&& int_at(stacks->a) > int_at(stacks->a->next))
			ps_swap_ab(stacks, 0);
		merge_a2(stacks, (1 << k), remaining);
	}
	return (1);
}

void merge_sort(t_stacks *stacks)
{
	int	k;
	int	ret_iter;

	init_divide(stacks);
	k = 1;
	ret_iter = 1;
	while (ret_iter)
	{
		ret_iter = sort_iteration(stacks, k);
		k++;
	}
}
