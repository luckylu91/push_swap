/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:39:46 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 15:35:31 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"
//
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			ret_args;

	//
	setbuf(stdout, NULL);
	ret_args = handle_args(&stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	printf("lalala");
	sort_rec_a(&stacks, stacks.a_size);
	free_stacks(&stacks);
	return (0);
}
