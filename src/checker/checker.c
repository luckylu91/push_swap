/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:47:26 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 02:42:24 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	ret;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (args_to_list(&a, argc, argv) == -1)
		return (error());
	if (repeating_numbers(a))
		return (error_free(&a, NULL));
	if (read_execute_cmds(&a, &b) == -1)
		return (error_free(&a, &b));
	ret = evaluate_final_state(a, b);
	free_stacks(&a, &b);
	print_result(ret);
	return (0);
}
