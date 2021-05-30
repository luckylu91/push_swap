/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:40:05 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 13:43:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

t_bilist	*pop_first(t_dequeue *q)
{
	t_bilist	*res;

	if (q->size == 0)
		return (NULL);
	res = q->first;
	if (q->size == 1)
	{
		q->first = NULL;
		q->last = NULL;
	}
	else
	{
		q->first = q->first->next;
		q->first->prev = NULL;
	}
	res->next = NULL;
	q->size--;
	return (res);
}

t_bilist	*pop_last(t_dequeue *q)
{
	t_bilist	*res;

	if (q->size == 0)
		return (NULL);
	res = q->last;
	if (q->size == 1)
	{
		q->first = NULL;
		q->last = NULL;
	}
	else
	{
		q->last = q->last->prev;
		q->last->next = NULL;
	}
	res->prev = NULL;
	q->size--;
	return (res);
}
