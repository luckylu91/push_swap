/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:19:21 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 11:58:51 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	valid_addition(t_pathinfo *p1, t_pathinfo *p2, int k)
{
	int		k1;
	int		k2;
	int		num_decr;
	t_list	*p2_path;
	int		max;

	num_decr = 0;
	k1 = *(int*)p1->path->content;
	p2_path = p2->path;
	while (p2_path)
	{
		k2 = *(int*)p2_path->content;
		if (k1 > k2)
		{
			if (num_decr == 0)
				max = *(int*)p1->path->content;
			num_decr++;
		}
		if (num_decr == 1 && k2 > max)
			return (0);
		if (num_decr > 1)
			return (0);
		if (k2 == k)
			return (1);
		k1 = k2;
		p2_path = p2_path->next;
	}
	return (1);
}

int	increase_pathinfo(t_pathinfo *p1, t_pathinfo *p2, int dist_12, int n)
{
	t_list	*p2_path_mov;
	t_list	*p2_dists_mov;
	int		k;
	int		dist_k;

	p2_path_mov = p2->path;
	p2_dists_mov = p2->dists;
	while (p2_path_mov)
	{
		k = *(int*)p2_path_mov->content;
		dist_k = *(int*)p2_dists_mov->content;
		if (dist_12 + dist_k >= n || !valid_addition(p1, p2, k))
			return (1);
		if (addback_item(p1, k, dist_12 + dist_k) == -1)
			return (-1);
		p2_path_mov = p2_path_mov->next;
		p2_dists_mov = p2_dists_mov->next;
	}
	return (1);
}

t_pathinfo	*go_farthest(t_permut *permut, int i, int j)
{
	t_pathinfo	*pi_new;
	t_pathinfo	*pj;
	// t_list		*pj_path_mov;
	// t_list		*pj_dists_mov;
	int			dist_ij;

	pi_new = ft_calloc(1, sizeof(t_pathinfo));
	if (!pi_new)
		return (NULL);
	if (addback_item(pi_new, i, 0) == -1)
		destroy_pathinfo(pi_new);
	pj = &permut->paths[j];
	dist_ij = dist_cycle(
		permut->val_indices[i],
		permut->val_indices[j],
		permut->n);
	if (increase_pathinfo(pi_new, pj, dist_ij, permut->n) == -1)
	{
		destroy_pathinfo(pi_new);
		return (NULL);
	}
	return (pi_new);
}

int	update_path(t_permut* permut, int i)
{
	int			j;
	t_pathinfo	*pi_new;
	int			max_len;
	int			min_tot_dist;
	t_pathinfo	*pi_max;

	// if (!permut->paths[i].path && addback_item(&permut->paths[i], i, 0) == -1)
	// 	return (-1);
	pi_max = NULL;
	max_len = -1;
	j = (i + 1) % permut->n;
	while (j != i)
	{
		pi_new = go_farthest(permut, i, j);
		if (!pi_new)
		{
			destroy_pathinfo(pi_max);
			free(pi_max);
			return (-1);
		}
		if (pi_new->len > max_len
			|| (pi_new->len == max_len && pi_new->tot_dist < min_tot_dist))
		{
			max_len = pi_new->len;
			min_tot_dist = pi_new->tot_dist;
			pi_max = pi_new;
		}
		else
		{
			destroy_pathinfo(pi_new);
			free(pi_new);
		}
		j = (j + 1) % permut->n;
	}
	destroy_pathinfo(&permut->paths[i]);
	permut->paths[i].len = pi_max->len;
	permut->paths[i].tot_dist = pi_max->tot_dist;
	permut->paths[i].path = pi_max->path;
	permut->paths[i].dists = pi_max->dists;
	free(pi_max);
	return (1);
}
