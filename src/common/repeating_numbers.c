/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeating_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:42:39 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 23:14:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	int_are_equals(void *i1_ptr, void *i2_ptr)
{
	int i1;
	int i2;

	if (!i1_ptr || !i2_ptr)
		return (1);
	i1 = *(int*)i1_ptr;
	i2 = *(int*)i2_ptr;
	return (i1 == i2);
}

int	repeating_numbers(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (ft_lstany(lst->next, lst->content, int_are_equals))
			return (1);
		lst = lst->next;
	}
	return (0);
}
