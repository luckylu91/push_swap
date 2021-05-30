/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:50:47 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 13:52:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

void	swap_if_needed(t_stacks *s)
{
	int op_bits;

	op_bits = 0;
	if (s->a->size >= 2 && int_at(s->a->first) > int_at(s->a->first->next))
		op_bits += 1;
	if (s->b->size >= 2 && int_at(s->b->first) < int_at(s->b->first->next))
		op_bits += 2;
	if (op_bits > 0)
		ps_swap_ab(s, op_bits - 1);
}

static int	adjust_na(t_stacks *s, int start, int na)
{
	int			max;
	t_bilist	*blst;

	if (na == 1)
		return (na);
	max = start + na - 1;
	blst = ft_bilststep(s->a->first, na - 1);
	while (na > 0 && int_at(blst) == max)
	{
		blst = blst->prev;
		max--;
		na--;
	}
	return (na);
}


static int	adjust_nb(t_stacks *s, int start, int nb)
{
	int			min;
	t_bilist	*blst;

	if (nb == 1)
		return (nb);
	min = start - (nb - 1);
	blst = ft_bilststep(s->b->first, nb - 1);
	while (nb > 0 && int_at(blst) == min)
	{
		blst = blst->prev;
		min++;
		nb--;
	}
	return (nb);
}

void	sort_rec_a(t_stacks *s, int start, int na)
{
	int na_next;
	int nb_next;

	printf("sort a: start = %d, na = %d\n", start, na);
	na = adjust_na(s, start, na);
	if (na <= 1)
		return ;
	if (na == 2)
	{
		swap_if_needed(s);
		return ;
	}
	na_next = push_half_in_b(s, start, na);
	nb_next = na - na_next;
	sort_rec_a(s, start + nb_next, na_next);
	sort_rec_b(s, start + nb_next - 1, nb_next);
}

void	sort_rec_b(t_stacks *s, int start, int nb)
{
	int	na_next;
	int	nb_next;
	int	nb_to_sort;
	int	nb_to_push;

	nb_to_sort = adjust_nb(s, start, nb);
	printf("sort b: start = %d, nb = %d, bb_to_sort = %d\n", start, nb, nb_to_sort);
	if (nb_to_sort <= 1)
	{
		while (nb-- > 0)
			ps_push_ab(s, 0);
		return ;
	}
	if (nb_to_sort == 2)
	{
		swap_if_needed(s);
		while (nb-- > 0)
			ps_push_ab(s, 0);
		return ;
	}
	na_next = push_half_in_a(s, start, nb_to_sort);
	nb_next = nb_to_sort - na_next;
	sort_rec_a(s, start - (na_next - 1), na_next);
	sort_rec_b(s, start - na_next, nb_next);
	nb_to_push = nb - na_next;
	while (nb_to_push > 0)
	{
		ps_push_ab(s, 0);
		nb_to_push--;
	}
}
