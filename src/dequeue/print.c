/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:45:51 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 13:44:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dequeue.h"

void	print_queue(t_dequeue *q, char *sep, char *end)
{
	t_bilist	*blst;

	blst = q->first;
	while (blst)
	{
		if (sep && blst->prev)
			ft_putstr_fd(sep, STDOUT_FILENO);
		ft_putnbr_fd(int_at(blst), STDOUT_FILENO);
		blst = blst->next;
	}
	if (end)
		ft_putstr_fd(end, STDOUT_FILENO);
}

void	print_queue_rev(t_dequeue *q, char *sep, char *end)
{
	t_bilist	*blst;

	blst = q->last;
	while (blst)
	{
		if (sep && blst->next)
			ft_putstr_fd(sep, STDOUT_FILENO);
		ft_putnbr_fd(int_at(blst), STDOUT_FILENO);
		blst = blst->prev;
	}
	if (end)
		ft_putstr_fd(end, STDOUT_FILENO);
}

void	print_stacks(t_stacks *s)
{
	ft_putstr_fd("b (tail) | ", STDOUT_FILENO);
	print_queue_rev(s->b, " ", NULL);
	ft_putstr_fd("|", STDOUT_FILENO);
	print_queue(s->a, " ", NULL);
	ft_putstr_fd("| a (tail)\n", STDOUT_FILENO);
}
