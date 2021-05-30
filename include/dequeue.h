/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:19:36 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 13:34:27 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

# include "libft.h"
# include "types.h"
# include "common.h"
# include <unistd.h>

t_dequeue	*new_dequeue(void);

void		push_top(t_dequeue *q, t_bilist *elem);
void		push_bottom(t_dequeue *q, t_bilist *elem);
void		addback_int(t_dequeue *q, int n);

t_bilist	*pop_first(t_dequeue *q);
t_bilist	*pop_last(t_dequeue *q);

t_dequeue	*sorted_queue(t_dequeue *q);

void		print_queue(t_dequeue *q, char *sep, char *end);
void		print_queue_rev(t_dequeue *q, char *sep, char *end);
void		print_stacks(t_stacks *s);

#endif
