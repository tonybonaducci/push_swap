/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:44:57 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/13 00:11:49 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node *end_node;

	if(!*stack || !(*stack)->next)
		return ;
	end_node = last_node(*stack);
	end_node->next = *stack;
	*stack = (*stack)->next;
	end_node->next->prev = end_node;
	end_node->next->next = NULL;
}

void ra(t_node **a, bool print)
{
	rotate(a);
	if(!print)
		ft_printf("ra\n");
}

void	rb(t_node **b, bool print)
{
	rotate(b);
	if(!print)
		ft_printf("ra\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
