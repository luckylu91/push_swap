/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 03:33:20 by lzins            ###   ########lyon.fr   */
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

	if (!alst || !(*alst)->next)
		return ;
	first = *alst;
	last_two(first, &last_prev, &last);
	*alst = last;
	last->next = first;
	last_prev->next = NULL;
}
