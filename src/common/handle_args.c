/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:36:42 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 16:21:49 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "pswap_recursion.h"
//
#include <stdio.h>

void	handle_args(t_stacks *stacks, int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (args_to_stacks(stacks, argc, argv))
		ft_exit();
	if (repeating_numbers(stacks->a))
		ft_exit();
	if (stacks->verbose)
		print_stacks_side(stacks);
	ft_get_set_exit_fun(exit_fun_ok);
}
