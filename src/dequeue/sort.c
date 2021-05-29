/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:39:19 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:07:37 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

static void	swap(t_bilist *x, t_bilist *y)
{
	swap_int(x->content, y->content);
}

static t_bilist	*partition(t_bilist *lo, t_bilist *hi)
{
	int			pivot;
	t_bilist	*i;
	t_bilist	*j;

	pivot = int_at(hi);
	i = lo;
	j = lo;
	while (j != hi)
	{
		if (int_at(j) < pivot)
		{
			swap(i, j);
			i = i->next;
		}
		j = j->next;
	}
	swap(i, hi);
	return (i);
}

static void	quicksort(t_bilist *lo, t_bilist *hi)
{
	t_bilist	*p;

	if (lo == hi)
		return ;
	p = partition(lo, hi);
	quicksort(lo, p->prev);
	quicksort(p->next, hi);
}

static t_dequeue	*copy(t_dequeue *q)
{
	t_dequeue	*q_cpy;
	t_bilist	*q_blst;

	q_cpy = ft_calloc(1, sizeof(t_dequeue));
	q_cpy->size = q->size;
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
