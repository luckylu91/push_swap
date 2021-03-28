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

int do_op(t_list **a, t_list **b, char *op_name)
{
	int ret;

	printf("%s\n\n", ft_strmapi(op_name, to_upper_fun));
	ret = parse_operation(a, b, op_name);
	return (ret);
}

int print_ab_together(t_list *a, t_list *b)
{
	printf("(b-end) ");
	ft_lstreviter_arg(b, " ", print_int);
	ft_putstr_fd("(b-head) | (a-head) ", STDOUT_FILENO);
	ft_lstiter_arg(a, " ", print_int);
	printf("(a-end)\n");
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
	print_ab_together(a, b);
	i = 0;
	while (ops[i])
	{
		if (do_op(&a, &b, ops[i]) == -1)
			printf("ERROR\n\n");
		print_ab_together(a, b);
		i++;
	}
}
