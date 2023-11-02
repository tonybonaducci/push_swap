/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:34:51 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/02 20:27:31 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_checker(char *av)
{
	int	i;
	
	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(&av[i]));
			return (0);
		i++;
	}
	return (1);
}

void	add_node(t_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;		
	}	
}

int	init_stack_a(t_node	**a, char **av)
{
	int		i;
	long 	nbr;

	i = 0;
	while (av[i])
	{
		if (!input_checker(av[i]));
			free_stack(av); //TODO
		nbr = ft_atol(av[i]); // TODO
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
		free_stack(a);
	if (dup_error(*a, (int)n));
		free_stack(a);
	add_node(a, (int)nbr); //TODO
	i++;
}