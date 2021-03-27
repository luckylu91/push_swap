/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 03:30:08 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	add_back_int(t_list **alst, int k)
{
	int *k_ptr;

	k_ptr = malloc(sizeof(int));
	if (!k_ptr)
		return (-1);
	*k_ptr = k;
	if (!ft_lstadd_back_content(alst, k_ptr))
	{
		free(k_ptr);
		return (-1);
	}
	return (1);
}

int	args_to_list(t_list **a, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (!ft_all_in(argv[i], "0123456789")
			|| add_back_int(a, ft_atoi(argv[i])) == -1)
			return (error_free(a, NULL));
		i++;
	}

}
