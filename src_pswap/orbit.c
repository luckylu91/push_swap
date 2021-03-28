/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orbit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:01:26 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 14:21:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int orbit_of(int *array, int n, int start, t_list **orbit_lst)
{
	int next;

	*orbit_lst = NULL;
	next = array[start];
	while (next != start)
	{
		if (ft_lstdupint_back(orbit_lst, next) == -1)
		{
			ft_lstclear(orbit_lst, free);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (-1);
		}
		next = array[next];
	}
	return (1);
}
