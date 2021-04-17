#include "pswap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stacks	*gstacks;
	int			ret_args;

	ret_args = handle_args(&stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	gstacks = groupstacks(&stacks);
	print_stacks_side(gstacks);
	push(&gstacks->a, &gstacks->b);
	print_stacks_side(gstacks);
	merge_ab_headtail(gstacks);
	print_stacks_side(gstacks);
}
