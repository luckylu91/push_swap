#include "pswap.h"
#include <stdio.h>

void	print_array(int *array, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[10] = {5, 0, 1, 3, 2, 4, 9, 6, 8, 7};
	t_permut *permut;

	permut = create_permut(array, 10);
	printf("permut array :\n");
	print_array(array, 10);
	printf("permut array with trans :\n");
	print_array(permut->array_trans, 10);
	printf("trans indices :\n");
	print_array(permut->trans_indices, 10);
	printf("values indices :\n");
	print_array(permut->val_indices, 10);
}
