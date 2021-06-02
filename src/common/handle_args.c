/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:36:42 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 03:30:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "pswap_recursion.h"
//
#include <stdio.h>

void	handle_args(t_stacks *stacks, int argc, char **argv)
{
	if (argc == 1)
		exit_ok();
	if (args_to_stacks(stacks, argc, argv))
		ft_exit();
	// if (stacks->verbose)
	// 	print_stacks(stacks);
	// printf("a_sorted : ");
	// print_queue(stacks->a_sorted, " ", "\n");
	replace_with_indexes(stacks);
	if (stacks->verbose)
		print_stacks(stacks);
}
