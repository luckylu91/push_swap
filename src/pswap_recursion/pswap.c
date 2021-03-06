/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:50:47 by lzins             #+#    #+#             */
/*   Updated: 2021/06/05 11:15:21 by lzins            ###   ########lyon.fr   */
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

	if (na <= 1)
		return (0);
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

	if (nb <= 1)
		return (0);
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

static void sort_3(t_stacks *s, int start, int op_code)
{
	int			last;
	t_dequeue	*q;

	if (op_code == 0)
	{
		last = start + 2;
		q = s->a;
	}
	else
	{
		last = start - 2;
		q = s->b;
	}
	if (int_at(q->first) == last)
		ps_rotate_ab(s, op_code);
	else if (int_at(q->first->next) == last)
		ps_rotate_reverse_ab(s, op_code);
	swap_if_needed(s);
}

void	sort_rec_a(t_stacks *s, int start, int na)
{
	// int na_next;
	// int nb_next;
	t_push_data d;
	int	na_to_sort;
	int	nb;
	// int	do_reverse;

	if (na == 3 && s->a->size == 3)
	{
		sort_3(s, start, 0);
		return ;
	}

	// printf("sort a: start = %d, na = %d\n", start, na);
	na_to_sort = na;
	if (na != s->a->size)
		na_to_sort = adjust_na(s, start, na);
	// printf("na_to_sort = %d\n", na_to_sort);
	// printf("s->a->size = %d\n", s->a->size);
	// print_stacks(s);
	if (na_to_sort <= 1)
		return ;
	if (na_to_sort == 2)
	{
		swap_if_needed(s);
		return ;
	}
	// if (na_to_sort == 3 && s->a->size == 3)
	// {
	// 	sort_3(s, start, 0);
	// 	return ;
	// }
	ft_bzero(&d, sizeof(t_push_data));
	d.n_tot = na_to_sort;
	set_push_data(s, 0, start, &d);
	nb = d.n_remaining;
	na_to_sort -= nb;
	push_half_part(s, 0, &d, na != s->a->size);

	// if (na < s->a->size)
		// na_next = push_half_in_b(s, start, na);
	// else
	// {
	// 	// printf("start = %d\nna = %d\n", start, na);
	// 	// printf("s.a = ");
	// 	// print_queue(s->a, " ", "\n");
	// 	push_half(s, 0, start, na);
	// 	na_next = na - na / 2;
	// }
	// nb_next = na - na_next;
	sort_rec_a(s, start + nb, na_to_sort);
	sort_rec_b(s, start + nb - 1, nb);
}

void	sort_rec_b(t_stacks *s, int start, int nb)
{
	// int	na_next;
	// int	nb_next;
	int	nb_to_sort;
	int na;
	t_push_data d;
	// int	do_reverse;

	if (nb == 3 && s->b->size == 3)
	{
		sort_3(s, start, 1);
		ps_push_n(s, 0, nb);
		return ;
	}

	// printf("nb = %d\n", nb);
	nb_to_sort = nb;
	if (nb != s->b->size)
		nb_to_sort = adjust_nb(s, start, nb);
	// printf("nb_to_s = %d\n", nb_to_sort);
	// printf("sort b: start = %d, nb = %d, nb_to_sort = %d\n", start, nb, nb_to_sort);
	// printf("b size = %d\n", s->b->size);
	// nb_to_sort = nb;
	if (nb_to_sort <= 1)
		ps_push_n(s, 0, nb);
	else if (nb_to_sort == 2)
	{
		swap_if_needed(s);
		ps_push_n(s, 0, nb);
	}
	// else if (nb_to_sort == 3 && s->b->size == 3)
	// {
	// 	printf("sort_3 b\n");
	// 	sort_3(s, start, 1);
	// 	ps_push_n(s, 0, nb);
	// }
	else
	{
		ft_bzero(&d, sizeof(t_push_data));
		d.n_tot = nb_to_sort;
		set_push_data(s, 1, start, &d);
		na = d.n_remaining;
		nb_to_sort -= na;
		push_half_part(s, 1, &d, nb != s->b->size);
		// if (nb_to_sort < s->b->size)
			// na_next = push_half_in_a(s, start, nb_to_sort);
		// else
		// {
		// 	push_half(s, 1, start, nb_to_sort);
		// 	na_next = nb_to_sort / 2;
		// }
		// nb_next = nb_to_sort - na_next;
		sort_rec_a(s, start - na + 1, na);
		sort_rec_b(s, start - na, nb_to_sort);
		if (nb_to_sort + na < nb)
			ps_push_n(s, 0, nb - na - nb_to_sort);
		// nb -= na_next;
	}
	// printf("end b\n");
	// print_trace();
	// printf("b will push %d\n", nb);
}
