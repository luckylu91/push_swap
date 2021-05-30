/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:33:06 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 15:31:33 by lzins            ###   ########lyon.fr   */
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

int	indices_true(t_dequeue *q, int n, t_bool_fun filter, int **res)
{
	t_bilist	*blst;
	int			num_indices;
	int			i;

	*res = ft_calloc(n, sizeof(int));
	num_indices = 0;
	blst = q->first;
	i = 0;
	while (blst)
	{
		if (filter(int_at(blst->content)))
			(*res)[num_indices++] = i;
		i++;
		blst = blst->next;
	}
	return (num_indices);
}

int	do_push_movement(t_stacks *s, int op_code, t_bool_fun filter,
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
		return ;
	if (mvt.direction > 0)
	{
		while (mvt.size-- > 0)
		{
			if (filter(int_at(q->first)))
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
			ps_rotate_ab(s, op_code);
			if (filter(int_at(q->first)))
			{
				ps_push_ab(s, 1 - op_code);
				n_push++;
			}
		}
	}
	return (n_push);
}

void	do_push_strategy(t_stacks *s, int op_code, t_bool_fun filter,
	t_push_movement strat[2])
{
	int	n_push;

	n_push = do_push_movement(s, op_code, filter, strat[0]);
	if (strat[0].direction > 0)
		ps_rotate_n(s, op_code, strat[0].size - n_push);
	else
		ps_rotate_reverse_n(s, op_code, strat[0].size - n_push);
	do_push_movement(s, op_code, filter, strat[1]);
}

static int	score_strat(int *indices, int n, int n_push, int k, int first_dir)
{
	int	nh;
	int	nt;
	int	dh;
	int	dt;

	if (k == 0)
		return (n - indices[0] + n_push);
	if (k == n_push)
		return (indices[n_push - 1]);
	nh = k;
	dh = indices[k - 1] + 1;
	nt = n_push - k;
	dt = n - indices[k];
	if (first_dir > 0)
		return (2 * dh - nh + dt + nt);
	else
		return (2 * dt + dh);
}


t_push_movement	best_push_strategy(t_dequeue *q, int n, t_bool_fun filter)
{
	int	n_push;
	int	*indices;
	int	k;
	int				score;
	int				score_min;
	t_push_movement	strat_min[2];

	score_min = -1;
	n_push = indices_true(q, n, filter, &indices);
	k = 0;
	while (k <= n_push)
	{
		score = score_strat(indices, n, n_push, k, -1);
		if (score < score_min || score_min == -1)
		{
			score_min = score;
			strat_min[0].direction = -1;
			strat_min[0].size = n_push - k;
			strat_min[1].direction = 1;
			strat_min[1].size = k;
		}
		score = score_strat(indices, n, n_push, k, 1);
		if (score < score_min || score_min == -1)
		{
			score_min = score;
			strat_min[0].direction = 1;
			strat_min[0].size = k;
			strat_min[1].direction = -1;
			strat_min[1].size = n_push - k;
		}
	}
}
