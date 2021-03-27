/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 03:03:46 by lzins            ###   ########lyon.fr   */
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
