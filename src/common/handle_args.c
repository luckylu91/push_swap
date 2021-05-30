/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:36:42 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 13:35:04 by lzins            ###   ########lyon.fr   */
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
	if (repeating_numbers(stacks->a->first))
		ft_exit();
	replace_with_indexes(stacks);
	if (stacks->verbose)
		print_stacks(stacks);
}
