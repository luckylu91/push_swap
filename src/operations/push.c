/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 16:26:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	push(t_list **alst1, t_list **alst2)
{
	t_list *first1_next;

	if (!*alst1)
		return 0;
	first1_next = (*alst1)->next;
	(*alst1)->next = *alst2;
	*alst2 = *alst1;
	*alst1 = first1_next;
	return (1);
}

int	push_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0 && push(&stacks->b, &stacks->a))
	{
		stacks->a_size++;
		stacks->b_size--;
	}
	else if (push(&stacks->a, &stacks->b))
	{
		stacks->a_size--;
		stacks->b_size++;
	}
	return (1);
}
