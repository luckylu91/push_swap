#include "pswap.h"
#include <stdio.h>

int main()
{
	int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	t_permut *permut;
	int i;
	t_list *chosen_path;
	t_list *remaining;

	permut = create_permut(array, 10);
	printf("permut array :\n");
	print_array(array, 10);
	printf("permut array with trans :\n");
	print_array(permut->array_trans, 10);
	printf("trans indices :\n");
	print_array(permut->trans_indices, 10);
	printf("values indices :\n");
	print_array(permut->val_indices, 10);
	i = 9;
	while (i >= 0)
	{
		printf("update %d:\n", i);
		update_path(permut, i);
		print_pathinfo(&permut->paths[i]);
		printf("\n");
		i--;
	}
	i = 9;
	while (i >= 0)
	{
		printf("update %d:\n", i);
		update_path(permut, i);
		print_pathinfo(&permut->paths[i]);
		printf("\n");
		i--;
	}
	chosen_path = chose_path(permut);
	print_int_list(chosen_path, "chosen path");
	select_remaining(permut, chosen_path, &remaining);
	print_int_list(remaining, "remaining");
	destroy_permut(permut);
	ft_lstclear(&chosen_path, free);
}
