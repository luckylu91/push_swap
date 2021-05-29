/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:04:25 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 15:20:11 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **alst)
{
	t_list *first;
	t_list *last;

	if (!*alst || !(*alst)->next)
		return ;
	first = *alst;
	last = ft_lstlast(*alst);
	*alst = first->next;
	last->next = first;
	first->next = NULL;
}

int	rotate_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		rotate(&stacks->a);
	else if (op_code == 1)
		rotate(&stacks->b);
	else
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
	}
	return (1);
}
