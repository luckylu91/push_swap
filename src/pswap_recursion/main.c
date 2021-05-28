/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:39:46 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 16:22:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"
//
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			ret_args;

	ft_get_set_exit_fun(exit_fun_error);
	handle_args(&stacks, argc, argv);
	sort_rec_a(&stacks, stacks.a_size);
	free_stacks(&stacks);
	return (0);
}
