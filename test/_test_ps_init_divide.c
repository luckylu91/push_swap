#include "pswap.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;
	int			ret_args;

	ret_args = handle_args(&stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	merge_sort(&stacks);
}
