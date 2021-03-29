/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:58 by lzins             #+#    #+#             */
/*   Updated: 2021/03/29 17:05:26 by lzins            ###   ########lyon.fr   */
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
int	orbit_of(int *array, int start, t_list **orbit_lst);
char	*orbit_str(t_list *num_lst);

#endif
