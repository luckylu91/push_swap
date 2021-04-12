/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_bij.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:03:05 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 15:56:14 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int	repetitions_sorted(int *array, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] == array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	map_input_to_perm(int *array, t_permut *permut)
{
	int i;

	i = 0;
	while (i < permut->n)
	{
		permut->array[i] = ft_intindex(permut->bijection, permut->n, array[i]);
		i++;
	}
}

int	compute_bijection(t_permut *permut, int *array, int n)
{
	copy_array(array, n, permut->bijection);
	bubble_sort(permut->bijection, n);
	if (repetitions_sorted(permut->bijection, n))
	{
		destroy_permut(permut);
		return (-1);
	}
	map_input_to_perm(array, permut);
	return (1);
}
