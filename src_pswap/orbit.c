/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orbit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:01:26 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:47:11 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int orbit_of(t_permut *permut, int start, t_list **orbit_lst)
{
	int next;

	*orbit_lst = NULL;
	next = permut->array[start];
	while (next != start)
	{
		if (ft_lstdupint_back(orbit_lst, next) == -1)
		{
			ft_lstclear(orbit_lst, free);
			return (-1);
		}
		next = permut->array[next];
	}
	return (1);
}
