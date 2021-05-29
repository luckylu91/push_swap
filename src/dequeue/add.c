/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:30:54 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:38:52 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

static void	push_first(t_dequeue *q, t_bilist *elem)
{
	q->first = elem;
	q->last = elem;
	elem->next = NULL;
	elem->prev = NULL;
}

void	push_top(t_dequeue *q, t_bilist *elem)
{
	if (q->size == 0)
		push_first(q, elem);
	else
	{
		q->first->prev = elem;
		elem->next = q->first;
		q->first = elem;
	}
	q->size++;
}

void	push_bottom(t_dequeue *q, t_bilist *elem)
{
	if (q->size == 0)
		push_first(q, elem);
	else
	{
		q->last->next = elem;
		elem->prev = q->last;
		q->last = elem;
	}
	q->size++;
}

void	addback_int(t_dequeue *q, int n)
{
	t_bilist	*elem;

	elem = NULL;
	ft_bilstdupint_back(&elem, n);
	push_bottom(q, elem);
}
