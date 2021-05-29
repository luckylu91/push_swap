/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:22:39 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:27:27 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

t_dequeue	*copy(t_dequeue *q)
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
