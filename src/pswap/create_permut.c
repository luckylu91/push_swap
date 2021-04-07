/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_permut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:24:36 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 17:07:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_permut	*create_permut(int *array, int n)
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
		|| !permut->bijection || !permut->val_indices || !permut->paths
		|| compute_bijection(permut, array, n) == -1)
	{
		destroy_permut(permut);
		return (NULL);
	}
	compute_indices(permut);
	compute_trans(permut);
	return (permut);
}
