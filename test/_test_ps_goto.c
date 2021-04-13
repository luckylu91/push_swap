#include "pswap.h"

//
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_pswap		*ps;
	t_stacks	stacks_init;
	int			ret_args;
	int			*array;

	ret_args = handle_args(&stacks_init, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	ps = create_pswap(stacks_init.n);
	if (!ps)
		return (error_free(&stacks_init));
	
	if (init_pswap(ps) == -1)
	{
		destroy_pswap(&ps);
		return (-1);
	}

	ps->path = chose_path(ps->permut);
	if (!ps->path || select_remaining(ps->permut, ps->path, &ps->remaining) == -1)
		return (-1);
	if (!ps->remaining)
		return (0);
	compute_spots(ps);
	go_to_first_rem(ps);
}