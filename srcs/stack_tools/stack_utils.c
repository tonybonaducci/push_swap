/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:34:51 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/13 20:47:49 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	long	ft_atol(const char *str)
{
	int	i;
	int	res;
	int	posneg;
	
	i = 0;
	res = 0;
	posneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			posneg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (res * posneg);
}


bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	add_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->val = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_node	**a, char **av)
{
	int		i;
	long 	nbr;

	i = 0;
	while (av[i])
	{
		if (!input_checker(av[i]))
			free_stack(a);
		nbr = ft_atol(av[i]); // TODO
	
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_stack(a);
		if (duplicate_check(*a, (int)nbr))
			free_stack(a);
		add_node(a, (int)nbr); 
		i++;
	}
}

t_node *get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node *get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	i;
	
	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;
	
	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node *find_min(t_node *stack)
{
	long	min;
	t_node	*min_node;
	
	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_node = stack;
		}
		stack = stack->next;	
	}
	return (min_node);
}
