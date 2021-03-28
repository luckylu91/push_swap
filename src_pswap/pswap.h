/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:58 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 14:22:05 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "libft.h"
#include <unistd.h>

typedef struct	s_bijection
{
	int	n;
	int	*values;
}				t_bijection;

int	mapto_1_n(int *array, int n, t_bijection *input_bij_1_n);
int orbit_of(int *array, int n, int start, t_list **orbit_lst);

#endif
