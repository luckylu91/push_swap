/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:39:46 by lzins             #+#    #+#             */
/*   Updated: 2021/06/04 21:23:01 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"
//
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	setbuf(stdout, NULL);
	//
	ft_get_set_exit_fun(exit_fun_error);
	handle_args(&stacks, argc, argv);
	sort_rec_a(&stacks, 0, stacks.a->size);
	exit_ok();
	return (0);
}
