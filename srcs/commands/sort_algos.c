#include "../../inc/push_swap.h"

static void double_rotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node ->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void rev_double_rotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	while(*b != cheapest_node -> target_node && *a != cheapest_node)
		rrr(a, b , false);
	current_index(*a);
	current_index(*b);
}

static void	a_to_b(t_node **a, t_node **b)
{
	t_node *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_med && cheapest_node->target_node->above_med)
		double_rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_med)
		&& !(cheapest_node->target_node->above_med))
		rev_double_rotate(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_node **a)
{
	while((*a)->val != find_min(*a)->val)
	{
		if (find_min(*a)->above_med)
			ra(a, false);
		else
			rra(a, false);
	}
}

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
		refresh_nodes_a(*a, *b);
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