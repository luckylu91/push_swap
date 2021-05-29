/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 16:14:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void last_two(t_list *lst, t_list **alast_prev, t_list **alast)
{
	*alast_prev = NULL;
	*alast = lst;
	while (lst->next)
	{
		*alast_prev = lst;
		*alast = lst->next;
		lst = lst->next;
	}
}

void	rotate_reverse(t_list **alst)
{
	t_list *first;
	t_list *last_prev;
	t_list *last;

	if (!*alst || !(*alst)->next)
		return ;
	first = *alst;
	last_two(first, &last_prev, &last);
	*alst = last;
	last->next = first;
	if (last_prev)
		last_prev->next = NULL;
}

int	rotate_reverse_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		rotate_reverse(&stacks->a);
	else if (op_code == 1)
		rotate_reverse(&stacks->b);
	else
	{
		rotate_reverse(&stacks->a);
		rotate_reverse(&stacks->b);
	}
	return (1);
}
