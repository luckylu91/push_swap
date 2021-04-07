#ifndef CHECKER_H
#define CHECKER_H

#include "libft.h"
#include "common.h"
#include "operations.h"
#include <unistd.h>

int	read_execute_cmds(t_stacks *stacks);
int	parse_operation(t_stacks *stacks, char *op_name);
int	check_ok(t_stacks *stacks);

#endif
