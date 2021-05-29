/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:39:19 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 11:36:35 by lzins            ###   ########lyon.fr   */
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

void	sort_queue(t_dequeue *q)
{
	if (q->size <= 1)
		return ;
	quicksort(q->first, q->last);
}
