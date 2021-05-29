/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:19:36 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 11:40:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

typedef struct	s_dequeue
{
	t_bilist	*first;
	t_bilist	*last;
	int			size;
}	t_dequeue;

void		push_top(t_dequeue *q, t_bilist *elem);
void		push_bottom(t_dequeue *q, t_bilist *elem);
void		addback_int(t_dequeue *q, int n);

t_bilist	*pop_first(t_dequeue *q);
t_bilist	*pop_last(t_dequeue *q);

void		sort_queue(t_dequeue *q);
