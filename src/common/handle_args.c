/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:36:42 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 13:37:58 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	handle_args(t_stacks *stacks, int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (args_to_stacks(stacks, argc, argv) == -1)
		return (-1);
	if (repeating_numbers(stacks->a))
		return (error_free(stacks));
	if (stacks->verbose)
		print_stacks_side(stacks);
	return (1);
}
