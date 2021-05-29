/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:33:06 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:41:54 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int	*list_to_array(t_bilist *lst, int n)
{
	int *array;
	int i;

	array = ft_calloc(n, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < n && lst)
	{
		array[i] = int_at(lst);
		lst = lst->next;
		i++;
	}
	return (array);
}

void	bubble_sort(int *array, int n)
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
