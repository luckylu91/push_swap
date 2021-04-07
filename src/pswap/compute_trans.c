/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_trans.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:27:03 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 16:04:16 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	values_prev_next_next(int (*values)[4], int i, t_permut *permut)
{
	int n;

	n = permut->n;
	(*values)[0] = permut->array[(i - 1 + n) % n];
	(*values)[2] = permut->array[i];
	(*values)[1] = permut->array[(i + 1) % n];
	(*values)[3] = permut->array[(i + 2) % n];
}

int	all_increasing(int values[4])
{
	int i;
	int num_decr;
	int min;
	int max;

	num_decr = 0;
	i = 0;
	while (i < 4)
	{
		if (values[i] > values[(i + 1) % 4])
		{
			num_decr++;
			max = values[i];
			min = values[(i + 1) % 4];
		}
		else if (num_decr == 1 && (values[i] < min || values[i] > max))
			return (0);
		if (num_decr > 1)
			return (0);
		i++;
	}
	return (1);
}

void	compute_trans(t_permut *permut)
{
	int i;
	int values[4];

	i = 0;
	while (i < permut->n)
	{
		values_prev_next_next(&values, i, permut);
		if (all_increasing(values))
		{
			permut->array_trans[i] = permut->array[(i + 1) % permut->n];
			permut->array_trans[(i + 1) % permut->n] = permut->array[i];
			permut->trans_indices[i] = 1;
			i += 2;
			continue ;
		}
		permut->array_trans[i] = permut->array[i];
		i++;
	}
}
