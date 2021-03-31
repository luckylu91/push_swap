/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:09:27 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:10:07 by lzins            ###   ########lyon.fr   */
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

void bubble_sort(int *array, int n)
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
