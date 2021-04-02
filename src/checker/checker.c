/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:47:26 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 14:02:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_params params;
	int	ret;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (handle_args(&a, &params, argc, argv) == -1)
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
