/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:30:00 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 22:38:20 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void push(t_node **dest, t_node **src)
{
	t_node	*pushed;
	
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		pushed->next = *dest;
		pushed->next->prev = pushed;
		*dest = pushed;		
	}
}

void pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
