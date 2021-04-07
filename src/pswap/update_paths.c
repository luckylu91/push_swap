/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:19:21 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 17:41:19 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	addback_item(t_pathinfo *pi, int val_path, int val_dist)
{
	if (ft_lstdupint_back(&pi->path, val_path) == -1
		|| ft_lstdupint_back(&pi->dists, val_dist) == -1)
		return (-1);
	return (1);
}

t_pathinfo	*go_farthest(t_permut *paths, int i, int j)
{
	t_pathinfo *pi;

	pi = ft_calloc(1, sizeof(t_pathinfo));
	if (!pi)
		return (NULL);
	if (addback_item(pi, i, 0) == -1)
		des

}

int	update_path(t_permut* permut, int i)
{
	int j;

	if (!permut->paths[i].path && addback_item(&permut->paths[i], i, 0) == -1)
		return (-1);
	j = (i + 1) % paths->n;
	while (j != i)
	{

		j = (j + 1) % paths->n;
	}
}
