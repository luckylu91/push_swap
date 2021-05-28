/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:20:06 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 16:20:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

int		exit_fun_error(void *ctx)
{
	(void)ctx;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (-1);
}

int		exit_fun_ok(void *ctx)
{
	return (0);
}
