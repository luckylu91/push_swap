/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:10:45 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:33:56 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	copy_array(int *array, int n, int *array_copy)
{
	ft_memcpy(array_copy, array, n * sizeof(int));
}
