/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:58:52 by lzins             #+#    #+#             */
/*   Updated: 2021/05/18 10:01:57 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	addback_item(t_pathinfo *pi, int val_path, int val_dist)
{
	if (ft_lstdupint_back(&pi->path, val_path) == -1
		|| ft_lstdupint_back(&pi->dists, val_dist) == -1)
		return (-1);
	pi->len++;
	pi->tot_dist = val_dist;
	return (1);
}

int	dist_cycle(int i, int j, int n)
{
	return ((j - i + n) % n);
}

int dist_cycle_values(int v1, int v2, t_permut *permut)
{
	int i;
	int j;

	i = permut->val_indices[v1];
	j = permut->val_indices[v2];
	return (dist_cycle(i, j, permut->n));
}

int	int_at(t_list *lst)
{
	return (*(int*)lst->content);
}
