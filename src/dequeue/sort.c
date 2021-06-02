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

static void	swap(t_bilist *x, t_bilist *y)
{
	// printf("swaping %d and %d\n", *(int*)x->content, *(int*)y->content);
	swap_int(x->content, y->content);
}

static int get_pivot(t_bilist *lo, t_bilist *hi)
{
	int	par;

	par = 0;
	while (lo != hi)
	{
		if (par % 2 == 0)
			hi = hi->prev;
		else
			lo = lo->next;
		par++;
	}
	return (int_at(lo));
}

static t_bilist	*partition(t_bilist *lo, t_bilist *hi)
{
	int			pivot;
	t_bilist	*i;
	t_bilist	*j;

	pivot = get_pivot(lo, hi);
	// printf("pivot = %d\n", pivot);
	i = lo;
	j = hi;
	while (1)
	{
		while (int_at(i) < pivot)
			i = i->next;
		while (int_at(j) > pivot)
			j = j->prev;
		if (int_at(i) >= int_at(j))
			return (j);
		swap(i, j);
	}
	return (NULL);
}

static void	quicksort(t_bilist *lo, t_bilist *hi)
{
	t_bilist	*p;

	if (lo == hi)
		return ;
	p = partition(lo, hi);
	if (p != lo && p->prev != lo)
		quicksort(lo, p->prev);
	if (p != hi && p->next != hi)
		quicksort(p->next, hi);
}

static t_dequeue	*copy(t_dequeue *q)
{
	t_dequeue	*q_cpy;
	t_bilist	*q_blst;

	q_cpy = ft_calloc(1, sizeof(t_dequeue));
	q_blst = q->first;
	while (q_blst)
	{
		addback_int(q_cpy, int_at(q_blst));
		q_blst = q_blst->next;
	}
	return (q_cpy);
}

t_dequeue	*sorted_queue(t_dequeue *q)
{
	t_dequeue	*q_copy;

	q_copy = copy(q);
	if (q->size > 1)
		quicksort(q_copy->first, q_copy->last);
	return (q_copy);
}
