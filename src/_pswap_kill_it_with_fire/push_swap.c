/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 09:21:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int argc, char **argv)
{
	t_pswap		ps;
	int			ret_args;
	int			*array;

	ft_bzero(&ps, sizeof(t_pswap));
	ret_args = handle_args(&ps.stacks_init, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	
	array = list_to_array(ps.stacks_init.a, ps.stacks_init.n);
	if (!array)
		return (error_free(&ps.stacks_init));
	ps.permut = create_permut(array, ps.stacks_init.n);

	if (array_to_stacks(&ps.stacks_bij, ps.permut->n, ps.permut->array_trans) == -1)
		return (-1);
	
	if (!ps.permut || update_all_paths(ps.permut) == -1)
	{
		destroy_permut(ps.permut);
		free(ps.path);
		return (error_free(&ps.stacks_init));
	}
	ps.path = chose_path(ps.permut);
	if (!ps.path || select_remaining(ps.permut, ps.path, &ps.remaining) == -1)
	{
		destroy_permut(ps.permut);
		free(ps.path);
		return (error_free(&ps.stacks_init));
	}
	if (!ps.remaining)
		return (0);
	go_to_first_rem(&ps);
	// push_all_rem(&ps);
}
