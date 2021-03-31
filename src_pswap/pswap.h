/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:58 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:47:59 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "libft.h"
#include <unistd.h>

typedef struct	s_permut
{
	int	n;
	int	*array;
	int	*bijection;
}				t_permut;

t_permut	*create_permut(int n);
void	destroy_permut(t_permut *permut);
void	copy_array(int *array, int n, int *array_copy);
void	bubble_sort(int *array, int n);
t_permut	*map_to_permut(int *array, int n); // no error printing
int	orbit_of(t_permut *permut, int start, t_list **orbit_lst);
char	*orbit_str(t_list *num_lst);

#endif
