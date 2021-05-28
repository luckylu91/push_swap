/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_permut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:24:36 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 11:33:45 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_permut	*create_permut(int n)
{
	t_permut *permut;

	permut = ft_calloc(1, sizeof(t_permut));
	if (!permut)
		return (NULL);
	permut->n = n;
	permut->array = ft_calloc(n, sizeof(int));
	permut->array_trans = ft_calloc(n, sizeof(int));
	permut->val_indices = ft_calloc(n, sizeof(int));
	permut->trans_indices = ft_calloc(n, sizeof(int));
	permut->bijection = ft_calloc(n, sizeof(int));
	permut->paths = ft_calloc(n, sizeof(t_pathinfo));
	if (!permut->array || !permut->array_trans || !permut->trans_indices
			|| !permut->bijection || !permut->val_indices || !permut->paths)
		destroy_permut(&permut);
	return (permut);
}

void	init_permut(t_permut *permut, int *array, int n)
{
	if (compute_bijection(permut, array, n) == -1)
		return (-1);
	compute_trans(permut);
	compute_indices(permut);
	if (update_all_paths(permut) == -1)
		return (-1);
}
