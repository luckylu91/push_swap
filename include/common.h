/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:14:05 by lzins             #+#    #+#             */
/*   Updated: 2021/05/28 16:22:03 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
#define COMMON_H

#include "libft.h"
#include <unistd.h>

typedef struct	s_stacks
{
	int	n;
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
	int	verbose;
	t_list	*a_sorted;
	t_list	*b_sorted;
}				t_stacks;

int		repeating_numbers(t_list *lst);
int		error(void);
int		error_free(t_stacks *stacks);
void	free_stacks(t_stacks *stacks);
int		lstrev_array(t_list *lst, int n, char ***array);
void	print_stacks_side(t_stacks *stacks);
int		args_to_stacks(t_stacks *stacks,int argc, char **argv);
void	handle_args(t_stacks *stacks, int argc, char **argv);
void	print_list(t_list *lst_int);
// utils
int		int_at(t_list *lst);
char	op_last_char(char op_char, int op_code);

#endif
