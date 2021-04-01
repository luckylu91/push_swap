/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:04:25 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 17:29:52 by lzins            ###   ########lyon.fr   */
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

int	rotate_ab(t_list **a, t_list **b, int op_code)
{
	if (op_code == 0)
		rotate(a);
	else if (op_code == 1)
		rotate(b);
	else
	{
		rotate(a);
		rotate(b);
	}
	return (1);
}
