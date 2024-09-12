/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:49:52 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/12 20:55:43 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

int	duplicate_check(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->val == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void free_error(t_node **a)
{
	free_stack(a);
	ft_printf("Input Error\n");
	exit(1);
}

void free_stack(t_node **stack)
{
	t_node *tmp;
	t_node *current;

	if (!stack)
		return;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->val = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
