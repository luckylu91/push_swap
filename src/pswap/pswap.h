/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:58 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 20:44:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "libft.h"
#include <unistd.h>

typedef struct	s_pathinfo
{
	int	len;
	t_list	*path;
	t_list	*dists;
}				t_pathinfo;

typedef struct	s_permut
{
	int	n;
	int	*array;
	int	*array_trans; // after initial tanspositions
	int	*trans_indices; // indices of the t1 in (t1 t2)
	int	*val_indices; // (after transpositions) ...[v] is the index of v in array_trans
	int	*bijection;
	t_pathinfo	*paths;
}				t_permut;

void	destroy_permut(t_permut *permut);
void	copy_array(int *array, int n, int *array_copy);
void	bubble_sort(int *array, int n);
int	compute_bijection(t_permut *permut, int *array, int n); // no error printing
int	all_increasing(int values[4]);
void	compute_trans(t_permut *permut);
void	compute_indices(t_permut *permut);
t_permut	*create_permut(int *array, int n);
void	destroy_pathinfo(t_pathinfo *pi);
int	update_path(t_permut* permut, int i);

int	orbit_of(t_permut *permut, int start, t_list **orbit_lst);
char	*orbit_str(t_list *num_lst);
void print_orbit(t_list *orbit);
int print_orbits(t_permut *permut);

#endif
