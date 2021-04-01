/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 17:29:35 by lzins            ###   ########lyon.fr   */
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

int	swap_ab(t_list **a, t_list **b, int op_code)
{
	if (op_code == 0)
		swap(a);
	else if (op_code == 1)
		swap(b);
	else
	{
		swap(a);
		swap(b);
	}
	return (1);
}
