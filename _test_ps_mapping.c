#include "pswap.h"

void print_int(void *iptr, void *sep)
{
	char	*sep_str;

	sep_str = (char*)sep;
	ft_putnbr_fd(*(int*)iptr, STDOUT_FILENO);
	ft_putstr_fd(sep_str, STDOUT_FILENO);
}

void print_array(int *array, int n, char *sep)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr_fd(array[i], STDOUT_FILENO);
		if (i < n - 1)
			ft_putstr_fd(sep, STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void print_orbit(int start, t_list *orbit)
{
	ft_putstr_fd("( ", STDOUT_FILENO);
	ft_putnbr_fd(start, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_lstiter_arg(orbit, " ", print_int);
	ft_putstr_fd(" )", STDOUT_FILENO);
}

int main(int argc, char **argv)
{
	int n = argc - 1;
	t_bijection bij;
	int *array = ft_calloc(n, sizeof(int));
	int i;

	i = 0;
	while (i < n)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	mapto_1_n(array, n, &bij);
	ft_putstr_fd("array: ", STDOUT_FILENO);
	print_array(array, n, ", ");
	ft_putstr_fd("bij.values: ", STDOUT_FILENO);
	print_array(bij.values, n, ", ");

	t_list *orbit;
	orbit_of(array, n, 0, &orbit);
	print_orbit(0, orbit);
}
