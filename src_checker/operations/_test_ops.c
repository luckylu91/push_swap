#include "checker.h"

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

static int	add_back_int(t_list **alst, int k)
{
	int *k_ptr;

	k_ptr = malloc(sizeof(int));
	if (!k_ptr)
		return (-1);
	*k_ptr = k;
	if (!ft_lstadd_back_content(alst, k_ptr))
	{
		free(k_ptr);
		return (-1);
	}
	return (1);
}

int main()
{
	t_list *lst = NULL;

	add_back_int(&lst, 0);
	add_back_int(&lst, 1);
	add_back_int(&lst, 2);
	add_back_int(&lst, 3);
	print_int_lst(lst);
	swap(&lst);
	print_int_lst(lst);
	rotate(&lst);
	print_int_lst(lst);
	rotate_reverse(&lst);
	print_int_lst(lst);
}
