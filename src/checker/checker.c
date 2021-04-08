/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:47:26 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:32:36 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (args_to_stacks(&stacks, argc, argv) == -1)
		return (-1);
	if (repeating_numbers(stacks.a))
		return (error_free(&stacks));
	if (stacks.verbose)
		print_stacks_side(&stacks);
	if (read_execute_cmds(&stacks) == -1)
		return (-1);
	free_stacks(&stacks);
	return (0);
}
