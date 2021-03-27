#ifndef CHECKER_H
#define CHECKER_H

#include "libft.h"
#include <unistd.h>

int	error(void);
int	error_free(t_list **a, t_list **b);
void	free_stacks(t_list **a, t_list **b);

int	args_to_list(t_list **a, int argc, char **argv);
int	repeating_numbers(t_list *lst);

void	push(t_list **alst1, t_list **alst2);
void	swap(t_list **alst);
void	rotate(t_list **alst);
void	rotate_reverse(t_list **alst);
int	push_ab(t_list **a, t_list **b, int op_code);
int	swap_ab(t_list **a, t_list **b, int op_code);
int	rotate_ab(t_list **a, t_list **b, int op_code);
int	rotate_reverse_ab(t_list **a, t_list **b, int op_code);
int	parse_operation(t_list **a, t_list **b, char *op_name);

#endif
