#include "pswap.h"
#include <stdio.h>

void *char_from_int(void *i)
{
	return (ft_itoa(*(int*)i));
}

void print_pathinfo(t_pathinfo *pi)
{
	t_list *path_str = ft_lstmap(pi->path, char_from_int, free);
	char *str1 = ft_lststrjoin(path_str, ", ", "", "");
	ft_lstclear(&path_str, free);
	t_list *dists_str = ft_lstmap(pi->dists, char_from_int, free);
	char *str2 = ft_lststrjoin(dists_str, ", ", "", "");
	ft_lstclear(&dists_str, free);
	printf("path  : %s\n", str1);
	printf("dists : %s\n", str2);
	free(str1);
	free(str2);
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
	int array[10] = {5, 0, 1, 3, 2, 4, 9, 6, 8, 7};
	t_permut *permut;
	int i;

	permut = create_permut(array, 10);
	i = 9;
	while (i >= 0)
	{
		printf("update %d:\n", i);
		update_path(permut, i);
		print_pathinfo(&permut->paths[i]);
		printf("\n");
		i--;
	}
}
