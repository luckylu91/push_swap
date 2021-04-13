#include "pswap.h"

static void	*int_to_str_ptr(void *i_ptr)
{
	int i;

	i = *(int*)i_ptr;
	return (ft_itoa(i));
}

char	*orbit_str(t_list *num_lst)
{
	t_list	*str_lst;
	char	*orbit_str;

	str_lst = ft_lstmap(num_lst, int_to_str_ptr, free);
	orbit_str = ft_lststrjoin(str_lst, " ", "(", ")");
	ft_lstclear(&str_lst, free);
	return (orbit_str);
}
