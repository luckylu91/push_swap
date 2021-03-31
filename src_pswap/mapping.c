/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:03:05 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:40:48 by lzins            ###   ########lyon.fr   */
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

t_permut *map_to_permut(int *array, int n)
{
	t_permut *permut;

	permut = create_permut(n);
	if (!permut)
		return (NULL);
	copy_array(array, n, permut->bijection);
	bubble_sort(permut->bijection, n);
	if (repetitions_sorted(permut->bijection, n))
	{
		destroy_permut(permut);
		return (NULL);
	}
	map_input_to_perm(array, permut);
	return (permut);
}
