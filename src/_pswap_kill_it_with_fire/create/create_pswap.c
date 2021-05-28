/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:59:55 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 11:38:43 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_pswap	*create_pswap(int n)
{
	t_pswap	*ps;

	ps = ft_calloc(1, sizeof(t_pswap));
	ps->stacks_init = ft_calloc(1, sizeof(t_stacks));
	ps->stacks_bij = ft_calloc(1, sizeof(t_stacks));
	ps->permut = create_permut(n);
	ps->path_array = ft_calloc(n, sizeof(int));
	ps->remaining_array = ft_calloc(n, sizeof(int));
	ps->spots_left = ft_calloc(n, sizeof(int));
	ps->spots_right = ft_calloc(n, sizeof(int));
	if (!ps->stacks_init || !ps->stacks_bij || !ps->permut
		|| !ps->path_array || !ps->remaining_array || !ps->spots_left
		|| !ps->spots_right)
		destroy_pswap(&ps);
	return (ps);
}

int	init_pswap(t_pswap *ps, t_stacks *stacks_init)
{
	int *array;

	*(ps->stacks_init) = *(stacks_init);
	ps->n = stacks_init->n;
	array = list_to_array(ps->stacks_init->a, ps->n);
	if (!array)
		return (-1);
	ps->permut = create_permut(ps->n);
	if (!ps->permut)
		return (-1);
	init_permut(ps->permut, array, ps->n);
	if (array_to_stacks(ps->stacks_bij, ps->n, ps->permut->array_trans) == -1)
		return (-1);
	return (0);
}
