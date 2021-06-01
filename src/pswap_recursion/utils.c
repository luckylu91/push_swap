/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:33:06 by lzins             #+#    #+#             */
/*   Updated: 2021/05/31 02:44:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int	*list_to_array(t_bilist *lst, int n)
{
	int *array;
	int i;

	array = ft_calloc(n, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < n && lst)
	{
		array[i] = int_at(lst);
		lst = lst->next;
		i++;
	}
	return (array);
}

// void	bubble_sort(int *array, int n)
// {
// 	int swap_happened;
// 	int i;
// 	int j;

// 	j = 0;
// 	swap_happened = 1;
// 	while (j < n - 1 && swap_happened)
// 	{
// 		swap_happened = 0;
// 		i = 0;
// 		while (i < n - 1 - j)
// 		{
// 			if (array[i] > array[i + 1])
// 			{
// 				swap_int(array + i, array + i + 1);
// 				swap_happened = 1;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

int	indices_true(t_dequeue *q, int n, t_bool_fun_arg filter, int **res)
{
	t_bilist	*blst;
	int			num_indices;
	int			i;

	*res = ft_calloc(n, sizeof(int));
	num_indices = 0;
	blst = q->first;
	i = 0;
	while (i < n)
	{
		if (filter.f(int_at(blst), filter.arg2))
			(*res)[num_indices++] = i;
		i++;
		blst = blst->next;
	}
	return (num_indices);
}

int	do_push_movement(t_stacks *s, int op_code, t_bool_fun_arg filter,
	t_push_movement mvt)
{
	t_dequeue	*q;
	int			n_push;

	n_push = 0;
	if (op_code == 0)
		q = s->a;
	else
		q = s->b;
	if (mvt.size == 0)
		return (0);
	if (mvt.direction < 0)
	{
		while (mvt.size-- > 0)
		{
			printf("size = %d\n", mvt.size);
			if (filter.f(int_at(q->first), filter.arg2))
			{
				ps_push_ab(s, 1 - op_code);
				n_push++;
			}
			else
				ps_rotate_reverse_ab(s, op_code);
		}
	}
	else
	{
		while (mvt.size-- > 0)
		{
			printf("size = %d\n", mvt.size);
			ps_rotate_ab(s, op_code);
			if (filter.f(int_at(q->first), filter.arg2))
			{
				ps_push_ab(s, 1 - op_code);
				n_push++;
			}
		}
	}
	return (n_push);
}

void	do_push_strategy(t_stacks *s, int op_code, t_bool_fun_arg filter,
	t_push_strat strat)
{
	int				n_push;
	t_push_movement	mvts[2];

	mvts[0].direction = strat.first_dir;
	mvts[1].direction = -strat.first_dir;
	if (strat.first_dir < 0)
	{
		mvts[0].size = strat.indices[strat.k - 1] + 1;
		if (strat.k < strat.n_push)
			mvts[1].size = strat.n - strat.indices[strat.k];
		else
			mvts[1].size = 0;
	}
	else
	{
		mvts[0].size = strat.n - strat.indices[strat.k];
		if (strat.k > 0)
			mvts[1].size = strat.indices[strat.k - 1] + 1;
		else
			mvts[1].size = 0;
	}
	n_push = do_push_movement(s, op_code, filter, mvts[0]);
	if (mvts[0].direction > 0)
		ps_rotate_n(s, op_code, mvts[0].size - n_push);
	else
		ps_rotate_reverse_n(s, op_code, mvts[0].size - n_push);
	do_push_movement(s, op_code, filter, mvts[1]);
}

static int	score_strat(int *indices, t_push_strat strat)
{
	int	nh;
	int	nt;
	int	dh;
	int	dt;

	if (strat.k == 0)
		return (strat.n - indices[0] + strat.n_push);
	if (strat.k == strat.n_push)
		return (indices[strat.n_push - 1]);
	nh = strat.k;
	dh = indices[strat.k - 1] + 1;
	nt = strat.n_push - strat.k;
	dt = strat.n - indices[strat.k];
	if (strat.first_dir < 0)
		return (2 * dh - nh + dt + nt);
	else
		return (2 * dt + dh);
}

t_push_strat	best_push_strategy(int *indices, int n_push, int n)
{
	int				score;
	int				score_min;
	t_push_strat	strat;
	t_push_strat	strat_min;

	score_min = -1;
	strat.indices = indices;
	strat.n = n;
	strat.n_push = n_push;
	strat.k = 0;
	while (strat.k <= strat.n_push)
	{
		strat.first_dir = -1;
		score = score_strat(indices, strat);
		if (score < score_min || score_min == -1)
		{
			score_min = score;
			strat_min = strat;
		}
		strat.first_dir = 1;
		score = score_strat(indices, strat);
		if (score < score_min || score_min == -1)
		{
			score_min = score;
			strat_min = strat;
		}
		strat.k++;
	}
	return (strat_min);
}

static int	less_equal(int x, int y)
{
	return (x <= y);
}

static int	great_equal(int x, int y)
{
	return (x >= y);
}


// void print_strat(t_push_strat strat)
// {
// 	// TO REMOVE
// 	printf("strat.first_dir = %d\n", strat.first_dir);
// 	printf("strat.k = %d\n", strat.k);
// 	printf("strat.n_push = %d\n", strat.n_push);
// }

void	push_half(t_stacks *s, int op_code, int start, int n)
{
	int	median;
	int	*indices;
	int	n_push;
	t_push_strat strat;
	t_bool_fun_arg filter;

	if (op_code == 0)
	{
		median = start + n / 2 - 1;
		filter.f = less_equal;
		filter.arg2 = median;
		n_push = indices_true(s->a, n, filter, &indices);
	}
	if (op_code == 1)
	{
		median = start - n / 2 + 1;
		filter.f = great_equal;
		filter.arg2 = median;
		n_push = indices_true(s->b, n, filter, &indices);
	}
	// n_push = n / 2
	strat = best_push_strategy(indices, n_push, n);
	// print_strat(strat);
	do_push_strategy(s, op_code, filter, strat);
	wrap_free(indices);
}
