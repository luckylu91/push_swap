/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_first_rem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:29:15 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:45:40 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	go_to_first_rem(t_pswap *ps)
{
	int	first_rem;
	int	first_rem_index;

	first_rem = int_at(ps->remaining);
	first_rem_index = ft_lstindex(ps->stacks_bij.a, &first_rem, sizeof(int));
	first_rem_index = dist_smallest(first_rem_index, ps->stacks_bij.n);
	ps_nrotate_ab(ps, first_rem_index, 0);
}
