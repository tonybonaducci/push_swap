#include "../../inc/push_swap.h"

void	simple_sort(t_node **a)
{
	t_node *biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra (a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
		if ((*a)->val > (*a)->next->val)
			sa(a, false);
}

void complex_sort(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a,b);
	}
	simple_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}