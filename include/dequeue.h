/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:19:36 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:36:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

# include "libft.h"
# include <unistd.h>

typedef struct	s_dequeue
{
	t_bilist	*first;
	t_bilist	*last;
	int			size;
}	t_dequeue;

t_dequeue	*new_dequeue(void);

void		push_top(t_dequeue *q, t_bilist *elem);
void		push_bottom(t_dequeue *q, t_bilist *elem);
void		addback_int(t_dequeue *q, int n);

t_bilist	*pop_first(t_dequeue *q);
t_bilist	*pop_last(t_dequeue *q);

t_dequeue	*sorted_queue(t_dequeue *q);

#endif
