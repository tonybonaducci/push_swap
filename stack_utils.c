/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:34:51 by rmenezes          #+#    #+#             */
/*   Updated: 2023/11/02 14:59:38 by rmenezes         ###   ########.fr       */
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


int	init_stack(t_node	**a, char **av)
{
	int		i;
	long 	n;

	i = 0;
	while (av[i])
	{
		if (!input_checker(av[i]));
			free_stack(av); //TODO
		n = ft_atol(av[i]); // TODO
	}
	if (n > INT_MAX || n < INT_MIN)
		free_stack(a);
	add_node(a, (int)n); //TODO
	i++;
}