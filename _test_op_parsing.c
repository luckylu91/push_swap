#include "checker.h"
#include <stdio.h>

void print_int(void *iptr)
{
	ft_putstr_fd("(", STDOUT_FILENO);
	ft_putnbr_fd(*(int*)iptr, STDOUT_FILENO);
	ft_putstr_fd(") -> ", STDOUT_FILENO);
}

void print_int_lst(t_list *lst)
{
	ft_lstiter(lst, print_int);
	ft_putstr_fd("END\n", STDOUT_FILENO);
}

void print_ab(t_list *a, t_list *b)
{
	printf("a: ");
	print_int_lst(a);
	printf("b: ");
	print_int_lst(b);
	printf("\n");
}

char to_upper_fun(unsigned int i, char c)
{
	return (ft_toupper(c));
}

int do_op_print(t_list **a, t_list **b, char *op_name)
{
	int ret;

	printf("%s\n\n", ft_strmapi(op_name, to_upper_fun));
	ret = parse_operation(a, b, op_name);
	print_ab(*a, *b);
	return (ret);
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

	setbuf(stdout, NULL);
	args_to_list(&a, argc, argv);
	print_ab(a, b);
	i = 0;
	while (ops[i])
	{
		if (do_op_print(&a, &b, ops[i]) == -1)
			printf("ERROR\n\n");
		i++;
	}
}
