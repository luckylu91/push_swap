/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 15:20:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **alst)
{
	t_list *tmp;

	if (!*alst || !(*alst)->next)
		return ;
	tmp = (*alst)->next;
	(*alst)->next = (*alst)->next->next;
	tmp->next = *alst;
	*alst = tmp;
}

int	swap_ab(t_stacks *stacks, int op_code)
{
	if (op_code == 0)
		swap(&stacks->a);
	else if (op_code == 1)
		swap(&stacks->b);
	else
	{
		swap(&stacks->a);
		swap(&stacks->b);
	}
	return (1);
}
