/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:59:58 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 11:28:58 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "libft.h"
#include "common.h"
#include "operations.h"
#include <unistd.h>
#include <stdio.h> //

typedef struct	s_pathinfo
{
	int	len;
	int	tot_dist;
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

// typedef struct	s_spot
// {
// 	int	left;
// 	int	right;
// 	int	n_remaining;
// }				t_spot;

typedef struct	s_pswap
{
	int			n;
	t_stacks	*stacks_init;
	t_stacks	*stacks_bij;
	t_permut	*permut;
	// t_list		*path;
	// t_list		*remaining;
	int			*path_array;
	int			*remaining_array;
	// t_spot		*spots;
	// int			n_spots;
	// int			*val_spot_array;
	int			*spots_left;
	int			*spots_right;
}				t_pswap;

int	addback_item(t_pathinfo *pi, int val_path, int val_dist);
int	dist_cycle(int i, int j, int n);
int dist_cycle_values(int v1, int v2, t_permut *permut);
int	dist_smallest(int i, int n);
int	int_at(t_list *lst);
void	list_to_bool_array(t_list *lst, int *array);
int	*list_to_array(t_list *lst, int n);
int	array_to_stacks(t_stacks *stacks, int n, int *array);
int	select_remaining(t_permut *permut, t_list *chosen_path, t_list **remaining);

void	ps_push_ab(t_pswap *ps, int op_code);
void	ps_swap_ab(t_pswap *ps, int op_code);
void	ps_rotate_ab(t_pswap *ps, int op_code);
void	ps_rotate_reverse_ab(t_pswap *ps, int op_code);
void	ps_nrotate_ab(t_pswap *ps, int n, int op_code);

void	destroy_permut(t_permut **permut_ptr);
t_permut	*create_permut(int n);
void	init_permut(t_permut *permut, int *array, int n);
t_pswap	*create_pswap(int n);
void	destroy_pswap(t_pswap **pswap_ptr);

void	copy_array(int *array, int n, int *array_copy);
void	bubble_sort(int *array, int n);
int	compute_bijection(t_permut *permut, int *array, int n); // no error printing
int	all_increasing(int values[4]);
void	compute_trans(t_permut *permut);
void	compute_indices(t_permut *permut);
void	destroy_pathinfo(t_pathinfo *pi);
int	update_path(t_permut* permut, int i);
int	update_all_paths(t_permut *permut);
t_list	*chose_path(t_permut *permut);

void	go_to_first_rem(t_pswap *ps);
int		compute_spots(t_pswap *ps);

// int	orbit_of(t_permut *permut, int start, t_list **orbit_lst);
// char	*orbit_str(t_list *num_lst);
// void print_orbit(t_list *orbit);
// int print_orbits(t_permut *permut);

//test
void	*char_from_int(void *i);
void	print_int_list(t_list *lst, char *name);
void	print_pathinfo(t_pathinfo *pi);
void	print_array(int *array, int n);

#endif
