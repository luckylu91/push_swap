/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:20:39 by lzins             #+#    #+#             */
/*   Updated: 2021/05/18 10:02:20 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*list_to_array(t_list *lst, int n)
{
	int *array;
	int i;

	array = ft_calloc(n, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!lst)
		{
			free(array);
			return (NULL);
		}
		array[i] = int_at(lst);
		lst = lst->next;
		i++;
	}
	return (array);
}

int	array_to_stacks(t_stacks *stacks, int n, int *array)
{
	int i;

	stacks->n = n;
	stacks->a_size = n;
	stacks->b_size = 0;
	i = 0;
	while (i < n)
	{
		if (ft_lstdupint_back(&stacks->a, array[i]) == -1)
			return (error_free(stacks));
		i++;
	}
	stacks->a_size = n;
	return (1);
}

void	list_to_bool_array(t_list *lst, int *array)
{
	while (lst)
	{
		array[int_at(lst)] = 1;
		lst = lst->next;
	}
}
