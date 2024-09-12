/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:28:10 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 22:26:25 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int median;

	i = 0;
	if (!stack);
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		++i;
	}
}

static void get_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node *target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val > best_match_index)
			{
				best_match_index = current_b->val;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_math_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost - a->index;
		if (!(a->above_med))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_med)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void set_cheapest(t_node *stack)
{
	long			cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value < stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prep_for_push(t_node **stack,
						t_node *top_node,
						char stack_id)
{
	while(*stack != top_node)
	{
		if (stack_id == 'a')
		{
			if (top_node->above_med)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (top_node->above_med)
				rb(stack, false);
			else
				rrb(stack,false);
		}
	}
}

void	refresh_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_math_a(a,b);
	set_cheapest(a);	
}
