/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:39:19 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 03:27:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

// algorithm quicksort(A, lo, hi) is
//     if lo < hi then
//         p := partition(A, lo, hi)
//         quicksort(A, lo, p)
//         quicksort(A, p + 1, hi)

// algorithm partition(A, lo, hi) is
//     pivot := A[ floor((hi + lo) / 2) ]
//     i := lo - 1
//     j := hi + 1
//     loop forever
//         do
//             i := i + 1
//         while A[i] < pivot
//         do
//             j := j - 1
//         while A[j] > pivot
//         if i ≥ j then
//             return j
//         swap A[i] with A[j]

static int	partition(int *array, int lo, int hi)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[(lo + hi) / 2];
	// printf("pivot = %d\n", pivot);
	i = lo;
	j = hi;
	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap_int(array + i, array + j);
	}
	return (-1);
}

static void	quicksort(int *array, int lo, int hi)
{
	int	p;

	if (lo >= hi)
		return ;
	p = partition(array, lo, hi);
	quicksort(array, lo, p - 1);
	quicksort(array, p + 1, hi);
}

// static t_dequeue	*copy(t_dequeue *q)
// {
// 	t_dequeue	*q_cpy;
// 	t_bilist	*q_blst;

// 	q_cpy = ft_calloc(1, sizeof(t_dequeue));
// 	q_blst = q->first;
// 	while (q_blst)
// 	{
// 		addback_int(q_cpy, int_at(q_blst));
// 		q_blst = q_blst->next;
// 	}
// 	return (q_cpy);
// }

static int	*to_array(t_dequeue *q)
{
	int			i;
	int			*array;
	t_bilist	*blst;

	array = wrap_malloc(q->size * sizeof(int));
	blst = q->first;
	i = -1;
	while (++i < q->size)
	{
		array[i] = int_at(blst);
		blst = blst->next;
	}
	return (array);
}

static t_dequeue	*to_queue(int *array, int size)
{
	t_dequeue	*q;
	int			i;
	int			*n;
	t_bilist	*new_elem;

	q = new_dequeue();
	i = -1;
	while (++i < size)
	{
		n = wrap_malloc(sizeof(int));
		*n = array[i];
		new_elem = ft_bilstnew(n);
		push_bottom(q, new_elem);
	}
	return (q);
}

t_dequeue	*sorted_queue(t_dequeue *q)
{
	int			*array;
	t_dequeue	*q_sorted;

	array = to_array(q);
	quicksort(array, 0, q->size - 1);
	q_sorted = to_queue(array, q->size);
	wrap_free(array);
	return (q_sorted);
}
