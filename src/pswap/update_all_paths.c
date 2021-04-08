/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_all_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:40:25 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:42:18 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	update_all_paths(t_permut *permut)
{
	int i;

	i = permut->n - 1;
	while (i >= 0)
	{
		if (update_path(permut, i) == -1)
			return (-1);
		i--;
	}
	i = permut->n - 1;
	while (i >= 0)
	{
		if (update_path(permut, i) == -1)
			return (-1);
		i--;
	}
	return (1);
}