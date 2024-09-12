/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouble_shuffle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:35:15 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 20:22:50 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	a_to_b(t_node **a, t_node **b)
{
	t_node *cheapest_node;
	
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_med && cheapest_node->target_node->above_med)
		double_rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_med)
		&& !(cheapest_node->target_node->above_median))
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