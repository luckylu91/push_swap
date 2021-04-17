#include "pswap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stacks	*gstacks;
	int			ret_args;

	ret_args = handle_args(&stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	gstacks = groupstacks(&stacks);
	printf("asize = %d\n", gstacks->a_size);
	printf("bsize = %d\n", gstacks->b_size);
	print_stacks_side(gstacks);
	push_ab(gstacks, 1);
	printf("asize = %d\n", gstacks->a_size);
	printf("bsize = %d\n", gstacks->b_size);
	print_stacks_side(gstacks);
	merge_ab_headtail(gstacks);
	printf("asize = %d\n", gstacks->a_size);
	printf("bsize = %d\n", gstacks->b_size);
	print_stacks_side(gstacks);

	free_stacks(gstacks);
	free(gstacks);
	free_stacks(&stacks);
}
