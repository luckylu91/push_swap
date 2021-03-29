#include "pswap.h"
#include <stdio.h>

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

void print_orbit(t_list *orbit)
{
	char *str;

	str = orbit_str(orbit);
	printf("%s\n", str);
	free(str);
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
	if (mapto_1_n(array, n, &bij) == -1)
		return (-1);
	ft_putstr_fd("array: ", STDOUT_FILENO);
	print_array(array, n, ", ");
	ft_putstr_fd("bij.values: ", STDOUT_FILENO);
	print_array(bij.values, n, ", ");

	t_list *orbit;
	orbit_of(array, 0, &orbit);
	print_orbit(orbit);
	printf("length of orbit : %d\n", ft_lstsize(orbit));
}
