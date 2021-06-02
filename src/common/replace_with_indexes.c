/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_with_indexes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:02:58 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 03:11:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	index_of(t_bilist *blst, int n)
{
	int	i;

	i = 0;
	while (int_at(blst) != n)
	{
		i++;
		blst = blst->next;
	}
	return (i);
}

void	replace_with_indexes(t_stacks *s)
{
	t_bilist	*blst;

	blst = s->a->first;
	while (blst)
	{
		// printf("Replacing %d with %d\n", *(int *)blst->content, index_of(s->a_sorted->first, int_at(blst)));
		*(int *)blst->content = index_of(s->a_sorted->first, int_at(blst));
		blst = blst->next;
	}
}
