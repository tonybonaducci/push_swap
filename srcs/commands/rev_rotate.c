/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:39:03 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 22:43:28 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void rev_rotate(t_node **stack)
{
	t_node *last;

	if(!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->prev = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void rra(t_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void rrb(t_node **b, bool print)
{
	rev_rotate(b);
	if(!print)
		ft_printf("rrb\n");
}

void rrr(t_node **a, t_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
