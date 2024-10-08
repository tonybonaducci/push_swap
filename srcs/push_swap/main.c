/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenezes <rmenezes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:44:30 by rmenezes          #+#    #+#             */
/*   Updated: 2024/09/20 02:15:47 by rmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(&a, av);
	if (!stack_sorted(a))
	{
		if( stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			simple_sort(&a);
		else
			complex_sort(&a, &b);
	}
	while (a)
	{
		printf("%d \n", a->val);
		a = a->next;
	}
	free_stack(&a);
	return (0);
}