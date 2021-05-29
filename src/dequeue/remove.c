/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:40:05 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:42:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

t_bilist	*pop_first(t_dequeue *q)
{
	t_bilist	*res;

	if (q->size == 0)
		return (NULL);
	res = q->first;
	q->first = q->first->next;
	q->first->prev = NULL;
	res->next = NULL;
	return (res);
}

t_bilist	*pop_last(t_dequeue *q)
{
	t_bilist	*res;

	if (q->size == 0)
		return (NULL);
	res = q->last;
	q->last = q->last->prev;
	q->last->next = NULL;
	res->prev = NULL;
	return (res);
}
