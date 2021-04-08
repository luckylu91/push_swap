/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:17:45 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:45:03 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	rotate_to(t_list **alst, t_list *new_head)
{
	t_list *lst;
	t_list *lst_prev;

	lst_prev = NULL;
	lst = *alst;
	while (lst)
	{
		if (lst == new_head)
			break;
		lst_prev = lst;
		lst = lst->next;
	}
	if (!lst_prev)
		return ;
	lst_prev->next = NULL;
	ft_lstlast(new_head)->next = *alst;
	*alst = new_head;
}

static t_list	*closest_from_start(t_permut *permut, t_list *path)
{
	int	start;
	t_list	*closest;
	int	dist;
	int	min_dist;

	start = permut->array_trans[0];
	min_dist = dist_cycle_values(start, *(int*)path->content, permut);
	closest = path;
	path = path->next;
	while (path)
	{
		dist = dist_cycle_values(start, *(int*)path->content, permut);
		if (dist < min_dist)
		{
			min_dist = dist;
			closest = path;
		}
		path = path->next;
	}
	return (closest);
}

t_list	*chose_path(t_permut *permut)
{
	t_list		*best_path;
	t_pathinfo	*pi;
	int			i;
	int			max_len;
	int			min_tot_dist;

	if (!permut)
		return (NULL);
	best_path = NULL;
	max_len = -1;
	i = 0;
	while (i < permut->n)
	{
		pi = &permut->paths[i]; 
		if (pi->len > max_len
			|| (pi->len == max_len && pi->tot_dist < min_tot_dist))
		{
			max_len = pi->len;
			best_path = pi->path;
			min_tot_dist = pi->tot_dist;
		}
		i++;
	}
	if (ft_lstcpy(best_path, &best_path, sizeof(int)) == -1)
		return (NULL);
	rotate_to(&best_path, closest_from_start(permut, best_path));
	return (best_path);
}
