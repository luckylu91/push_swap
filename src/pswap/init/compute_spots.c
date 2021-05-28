/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_spots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:36 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 10:43:30 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

// static int	discontinuity(int i, int j, int n)
// {
// 	int d;

// 	d = dist_cycle(i, j, n);
// 	if (d == 1 || d == -1)
// 		return (0);
// 	return (1);
// }

//hihihi

// assert len(path) >= 2
// static int	count_spots(t_list *path, int n)
// {
// 	t_list	*path_mov;
// 	int		n_spots;
// 	int		kpath;
// 	int		kpath_next;

// 	n_spots = 0;
// 	path_mov = path;
// 	while (path_mov->next)
// 	{
// 		kpath = int_at(path_mov); //--__==___+==--__+-_++_+==+_+_+--=+_)-=)_+=-(+_(*C _dobsvs))
// 		kpath_next = int_at(path_mov->next);
// 		if (discontinuity(kpath, kpath_next, n))
// 			n_spots++;
// 		path_mov = path_mov->next;
// 	}// hoho
// 	if (discontinuity(kpath_next, int_at(path), n))
// 		n_spots++;
// 	printf("(count_spots)\n");
// 	print_int_list(path, "path");
// 	printf("n_spots = %d\n", n_spots);
// 	return (n_spots);
// }

// static int	fill_spots(t_pswap *ps)
// {
// 	t_list	*path_mov;
// 	t_list	*a_mov;
// 	int		n_spots;
// 	int		ka;
// 	int		kpath;
// 	int		kpath_next;

// 	path_mov = ps->path;
// 	a_mov = ps->stacks_bij.a;
// 	n_spots = 0;
// 	while (a_mov)
// 	{
// 		kpath = int_at(path_mov); //--__==___+==--__+-_++_+==+_+_+--=+_)-=)_+=-(+_(*C _dobsvs))
// 		kpath_next = int_at(path_mov->next);
// 		ka = int_at(a_mov);
// 		if (discontinuity(kpath, kpath_next, ps->stacks_bij.n))
// 		{
// 			n_spots++;
// 		}
// 		a_mov = a_mov->next;
// 	}// hoho
// 	if (discontinuity(kpath_next, int_at(path), n))
// 		n_spots++;
// }

static void	fill_spots_right(t_pswap *ps)
{
	t_list	*path_mov;
	t_list	*a_mov;
	int		kpath;
	int		ka;

	path_mov = ps->path;
	a_mov = ps->stacks_bij.a;
	kpath = int_at(path_mov);
	while (a_mov)
	{
		ka = int_at(a_mov);
		if (ka == kpath)
		{
			path_mov = path_mov->next;
			if (!path_mov)
				kpath = int_at(ps->path);
			else
				kpath = int_at(path_mov);
		}
		else
			ps->spots_right[ka] = kpath;
		a_mov = a_mov->next;
	}// hoho
}
static void	fill_spots_left(t_pswap *ps)
{
	int i;
	int sp_left;
	int i_again;

	i_again = 0;
	sp_left = -1;
	i = 0;
	while (i < ps->stacks_bij.n)
	{
		if (ps->spots_right[i] == 0)
		{
			i_again = i;
			sp_left = i;
		}
		else if (sp_left >= 0)
			ps->spots_left[i] = sp_left;
		i++;
	}
	i = 0;
	while (i < i_again)
	{
		if (ps->spots_right[i] != 0)
			ps->spots_left[i] = sp_left;
		i++;
	}
}

int	compute_spots(t_pswap *ps)
{
	if (!ps->path || ft_lstsize(ps->path) == ps->stacks_bij.n)
		return (0);
	// ps->val_spot_array = ft_calloc(ps->stacks_bij.n, sizeof(int));
	// if (!ps->val_spot_array)
	// 	return (-1);
	// ps->n_spots = count_spots(ps->path, ps->permut->n);
	// ps->spots = ft_calloc(ps->n_spots, sizeof(t_spot));
	// if (!ps->spots)
	// 	return (-1);
	ps->spots_left = ft_calloc(ps->stacks_bij.n, sizeof(int));
	ps->spots_right = ft_calloc(ps->stacks_bij.n, sizeof(int));
	fill_spots_right(ps);
	fill_spots_left(ps);
	printf("spots_left = ");
	print_array(ps->spots_left, ps->stacks_bij.n);
	printf("spots_right = ");
	print_array(ps->spots_right, ps->stacks_bij.n);
	return (0);
}
