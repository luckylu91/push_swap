/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:50:47 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:10:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

void	swap_if_needed(t_stacks *s)
{
	int op_bits;

	op_bits = 0;
	if (s->a_size >= 2 && int_at(s->a) > int_at(s->a->next))
		op_bits += 1;
	if (s->b_size >= 2 && int_at(s->b) < int_at(s->b->next))
		op_bits += 2;
	if (op_bits > 0)
		ps_swap_ab(s, op_bits - 1);
}

static int	correct_na(t_stacks *s, int na)
{
	
}

void	sort_rec_a(t_stacks *s, int na)
{
	int na_next;

	na = correct_na(s, na);
	if (na == 1)
		return ;	
	if (na == 2)
	{
		swap_if_needed(s);
		return ;
	}
	na_next = push_half_in_b(s, na);
	sort_rec_a(s, na_next);
	sort_rec_b(s, na - na_next);
}

void	sort_rec_b(t_stacks *s, int nb)
{
	int	na_next;
	int	n_rem;

	if (nb == 1)
	{
		ps_push_ab(s, 0);
		return ;
	}
	if (nb == 2)
	{
		swap_if_needed(s);
		ps_push_ab(s, 0);
		ps_push_ab(s, 0);
		return ;
	}
	na_next = push_half_in_a(s, nb);
	sort_rec_a(s, na_next);
	sort_rec_b(s, nb - na_next);
	n_rem = nb - na_next;
	while (n_rem > 0)
	{
		ps_push_ab(s, 0);
		n_rem--;
	}
}
