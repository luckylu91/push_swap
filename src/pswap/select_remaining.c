/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_remaining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:40 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:46:05 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	select_remaining(t_permut *permut, t_list *chosen_path, t_list **remaining)
{
	int		*chosen_array;
	int		i;

	if (!permut || !chosen_path)
		return (NULL);
	*remaining = NULL;
	chosen_array = ft_calloc(permut->n, sizeof(int));
	while (chosen_path)
	{
		chosen_array[int_at(chosen_path)] = 1;
		chosen_path = chosen_path->next;
	}
	i = 0;
	while (i < permut->n)
	{
		if (!chosen_array[permut->array_trans[i]]
			&& !ft_lstdupint_back(remaining, permut->array_trans[i]))
		{
			ft_lstclear(remaining, free);
			return (-1);
		}
		i++;
	}
	return (1);
}
