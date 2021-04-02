/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:08:14 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 14:12:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_sorted_lst(t_list *lst)
{
	int tmp1;
	int tmp2;

	if (!lst)
		return (1);
	tmp1 = *(int*)lst->content;
	lst = lst->next;
	while (lst)
	{
		tmp2 = *(int*)lst->content;
		if (tmp2 < tmp1)
			return (0);
		tmp1 = tmp2;
	}
	return (1);
}
