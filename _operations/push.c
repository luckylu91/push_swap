/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:26:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push(t_bilist **alst1, t_bilist **alst2)
{
	t_bilist *second1;

	if (!*alst1)
		return (0);
	second1 = (*alst1)->next;
	(*alst1)->next = *alst2;
	*alst2 = *alst1;
	*alst1 = second1;
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
