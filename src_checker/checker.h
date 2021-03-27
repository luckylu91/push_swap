#ifndef CHECKER_H
#define CHECKER_H

#include "libft.h"
#include <unistd.h>

int	error(void);
int	error_free(t_list **a, t_list **b);
void	free_stacks(t_list **a, t_list **b);
int	args_to_list(t_list **a, int argc, char **argv);
int	repeating_numbers(t_list *lst);
void	swap(t_list **alst);
void	rotate(t_list **alst);
void	rotate_reverse(t_list **alst);

#endif
