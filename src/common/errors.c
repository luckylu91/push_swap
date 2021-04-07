/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:24:08 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 15:14:20 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (-1);
}

int	error_free(t_stacks *stacks)
{
	free_stacks(stacks);
	return (error());
}
