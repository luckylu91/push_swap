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

void	rotate_permut(t_permut *permut)
{
	int i;
	int tmp;

	if (permut->n <= 1)
		return ;
	tmp = permut->array[0];
	i = 0;
	while (i < permut->n - 1)
	{
		permut->array[i] = permut->array[i + 1];
		i++;
	}
	permut->array[permut->n - 1] = tmp;
}

int main(int argc, char **argv)
{
	int n = argc - 1;
	t_permut *permut;
	int *array = ft_calloc(n, sizeof(int));
	int i;

	setbuf(stdout, NULL);
	i = 0;
	while (i < n)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	permut = create_permut(array, n);
	// permut = map_to_permut(array, n);
	if (!permut)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	ft_putstr_fd("array: ", STDOUT_FILENO);
	print_array(array, n, ", ");
	ft_putstr_fd("permut->array: ", STDOUT_FILENO);
	print_array(permut->array, n, ", ");
	ft_putstr_fd("permut->bijection: ", STDOUT_FILENO);
	print_array(permut->bijection, n, ", ");

	t_list *orbit;
	if (orbit_of(permut, 0, &orbit) == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	print_orbit(orbit);
	printf("\n");
	printf("length of orbit : %d\n", ft_lstsize(orbit));
	i = 0;
	while (i < permut->n)
	{
		printf("---\ni=%d\n", i);
		print_orbits(permut);
		printf("\n");
		rotate_permut(permut);
		i++;
	}
}
