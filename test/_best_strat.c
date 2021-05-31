#include "pswap_recursion.h"
#include <stdio.h>

void print_strat(t_push_strat strat)
{
	printf("strat.first_dir = %d\n", strat.first_dir);
	printf("strat.k = %d\n", strat.k);
	printf("strat.n_push = %d\n", strat.n_push);
}

int main()
{
	int	*indices = calloc(10, sizeof(int));
	t_push_strat	strat;

	indices[0] = 9;
	indices[1] = 7;
	strat = best_push_strategy(indices, 1, 10);
	print_strat(strat);
}
