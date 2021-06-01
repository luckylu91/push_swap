#include "libft.h"
#include <execinfo.h>
#include <stdio.h>

void	print_trace(void)
{
	char	**strs;
	void	*callstack[128];
	int		size;
	int		i;

	size = backtrace(callstack, 128);
	strs = backtrace_symbols(callstack, size);
	for (i = 0; i < size ; i++)
	{
		printf("%s\n", strs[i]);
	}
	free(strs);
}