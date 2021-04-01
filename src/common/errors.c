/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:24:08 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 02:30:40 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (-1);
}

int	error_free(t_list **a, t_list **b)
{
	free_stacks(a, b);
	return (error());
}
