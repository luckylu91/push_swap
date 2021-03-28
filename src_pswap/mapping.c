/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:03:05 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 13:57:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void bubble_sort(int *array, int n)
{
	int swap_happened;
	int i;
	int j;

	j = 0;
	swap_happened = 1;
	while (j < n - 1 && swap_happened)
	{
		swap_happened = 0;
		i = 0;
		while (i < n - 1 - j)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i + 1);
				swap_happened = 1;
			}
			i++;
		}
		j++;
	}
}

static int repetitions_sorted(int *array, int n)
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

static void	transform_input(int *array, int n, t_bijection *input_bij_1_n)
{
	int i;

	i = 0;
	while (i < n)
	{
		array[i] = ft_intindex(input_bij_1_n->values, n, array[i]);
		i++;
	}
}

int	mapto_1_n(int *array, int n, t_bijection *input_bij_1_n)
{
	int	*array_copy;

	array_copy = ft_calloc(1, sizeof(int));
	if (!array_copy)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	ft_memcpy(array_copy, array, n * sizeof(int));
	bubble_sort(array_copy, n);
	if (repetitions_sorted(array, n))
	{
		free(array_copy);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	input_bij_1_n->n = n;
	input_bij_1_n->values = array_copy;
	transform_input(array, n, input_bij_1_n);
	return (1);
}
