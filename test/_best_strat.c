#include "pswap_recursion.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	// int	*indices = calloc(10, sizeof(int));
	// t_push_strat	strat;
	t_stacks	s;

	setbuf(stdout, NULL);
	// indices[0] = 9;
	// indices[1] = 7;
	// strat = best_push_strategy(indices, 1, 10);
	// print_strat(strat);
	handle_args(&s, argc, argv);
	printf("s.n = %d\n", s.n);
	printf("s.a = ");
	print_queue(s.a, " ", "\n");
	printf("s.a_sorted = ");
	print_queue(s.a_sorted, " ", "\n");
	push_half(&s, 0, 0, s.n);
}
