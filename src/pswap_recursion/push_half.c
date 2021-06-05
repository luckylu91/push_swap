#include "pswap_recursion.h"

static t_dequeue	*queue_from_code(t_stacks *s, int op_code)
{
	if (op_code == 0)
		return (s->a);
	else
		return (s->b);
}

void	set_push_data(t_stacks *s, int op_code, int start, t_push_data *d)
{
	int			i;
	t_bilist	*blst;
	int			inc;

	inc = (-2 * op_code + 1);
	d->ref = start + inc * d->n_tot / 2;
	if (op_code == 0)
		d->test_keep = great_equal;
	else
		d->test_keep = less_equal;
	d->q = queue_from_code(s, op_code);
	i = -1;
	blst = d->q->first;
	while (++i < d->n_tot)
	{
		if (!d->test_keep(int_at(blst), d->ref))
			d->n_remaining++;
		blst = blst->next;
	}
}

void	push_half_part(t_stacks *s, int op_code, t_push_data *d, int do_reverse)
{
	if (d->n_remaining == 0)
		return ;
	if (d->test_keep(int_at(d->q->first), d->ref))
	{
		ps_rotate_ab(s, op_code);
		push_half_part(s, op_code, d, do_reverse);
		if (do_reverse)
			ps_rotate_reverse_ab(s, op_code);
	}
	else
	{
		ps_push_ab(s, 1 - op_code);
		d->n_remaining--;
		push_half_part(s, op_code, d, do_reverse);
	}
}
