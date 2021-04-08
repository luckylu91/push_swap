#include "checker.h"
#include <stdio.h>

void print_int(void *iptr, void *sep)
{
	char	*sep_str;

	sep_str = (char*)sep;
	ft_putstr_fd("(", STDOUT_FILENO);
	ft_putnbr_fd(*(int*)iptr, STDOUT_FILENO);
	ft_putstr_fd(")", STDOUT_FILENO);
	ft_putstr_fd(sep_str, STDOUT_FILENO);
}

void print_int_lst(t_list *lst)
{
	ft_lstiter_arg(lst, " -> ", print_int);
	ft_putstr_fd("END\n", STDOUT_FILENO);
}

void print_ab(t_stacks *stacks)
{
	printf("a: ");
	print_int_lst(stacks->a);
	printf("b: ");
	print_int_lst(stacks->b);
	printf("\n");
}

char to_upper_fun(unsigned int i, char c)
{
	return (ft_toupper(c));
}

int do_op(t_stacks *stacks, char *op_name)
{
	int ret;

	printf("\n%s\n", ft_strmapi(op_name, to_upper_fun));
	ret = parse_operation(stacks, op_name);
	return (ret);
}

int print_ab_together(t_stacks *stacks)
{
	printf("(b-end) ");
	ft_lstreviter_arg(stacks->b, " ", print_int);
	ft_putstr_fd("(b-head) | (a-head) ", STDOUT_FILENO);
	ft_lstiter_arg(stacks->a, " ", print_int);
	printf("(a-end)\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_list *a = NULL;
	t_list *b = NULL;
	char *ops[100] = {
		"pb", "pb", "pb", "pb", "pb",
		"pa", "pb", "ra", "rb", "rr", "sa", "sb", "ss", "rra", "rrb", "rrr", NULL
	};
	int i = 0;
	t_stacks stacks;

	setbuf(stdout, NULL);
	if (args_to_stacks(&stacks, argc, argv) == -1)
		return (-1);
	print_ab_together(&stacks);
	i = 0;
	while (ops[i])
	{
		if (do_op(&stacks, ops[i]) == -1)
			printf("ERROR\n\n");
		print_stacks_side(&stacks);
		i++;
	}
}
