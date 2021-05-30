/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:14:05 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 11:09:08 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "types.h"
# include "dequeue.h"
# include <unistd.h>


int		repeating_numbers(t_bilist *lst);
int		error(void);
int		error_free(t_stacks *stacks);
int		lstrev_array(t_bilist *lst, int n, char ***array);
void	print_stacks_side(t_stacks *stacks);
int		args_to_stacks(t_stacks *stacks,int argc, char **argv);
void	handle_args(t_stacks *stacks, int argc, char **argv);
void	print_list(t_bilist *lst_int);
// utils
int		int_at(t_bilist *lst);
char	op_last_char(char op_char, int op_code);
void	swap_int(int *n, int *p);

void	replace_with_indexes(t_stacks *s);

#endif
