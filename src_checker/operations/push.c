/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 17:29:23 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_list **alst1, t_list **alst2)
{
	t_list *first1_next;

	if (!*alst1)
		return ;
	first1_next = (*alst1)->next;
	(*alst1)->next = *alst2;
	*alst2 = *alst1;
	*alst1 = first1_next;
}

int	push_ab(t_list **a, t_list **b, int op_code)
{
	if (op_code == 0)
		push(b, a);
	else
		push(a, b);
	return (1);
}
