#include "pswap.h"
#include <stdio.h>

void	print_array(int array[4])
{
	int i;

	i = -1;
	while (++i < 4)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int	present_before(int array[4], int i, int n)
{
	while (--i >= 0)
	{
		if (array[i] == n)
			return (1);
	}
	return (0);
}

void	test_perm(int array[4], int i)
{
	int j;

	if (i == 4)
	{
		print_array(array);
		printf("all_increasing: %d\n", all_increasing(array));
	}
	else
	{
		j = 0;
		while (j < 4)
		{
			if (!present_before(array, i, j))
			{
				array[i] = j;
				test_perm(array, i + 1);
			}
			j++;
		}
	}
}

int main()
{
	int array[4];

	test_perm(array, 0);
}