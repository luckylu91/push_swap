/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:47:26 by lzins             #+#    #+#             */
/*   Updated: 2021/06/04 18:18:36 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	ft_get_set_exit_fun(exit_fun_error);
	handle_args(&stacks, argc, argv);
	read_execute_cmds(&stacks);
	exit_ok();
	return (0);
}
