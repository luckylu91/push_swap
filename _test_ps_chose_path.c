#include "pswap.h"
#include <stdio.h>

void *char_from_int(void *i)
{
	return (ft_itoa(*(int*)i));
}

void print_int_list(t_list *lst, char *name)
{
	t_list *path_str = ft_lstmap(lst, char_from_int, free);
	char *str = ft_lststrjoin(path_str, ", ", "", "");
	ft_lstclear(&path_str, free);
	printf("%s\t: %s\n", name, str);
	free(str);
}

void print_pathinfo(t_pathinfo *pi)
{
	print_int_list(pi->path, "path");
	print_int_list(pi->dists, "dists");
	printf("len : %d\n", pi->len);
}

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
